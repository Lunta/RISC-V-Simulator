// See LICENSE for license details.

#include "elf.h"
#include "memif.h"
#include <cstring>
#include <string>
#include <sys/stat.h>
#include <fcntl.h>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <map>
#include <Windows.h>

template<class ehdr_t, class phdr_t, class shdr_t, class sym_t>
void LOAD_ELF(memif_t* memif, reg_t* entry, char* buf, const size_t size, std::vector<uint8_t>& zeros, std::map<std::string, uint64_t>& symbols) {
	ehdr_t* eh = (ehdr_t*)buf;
	phdr_t* ph = (phdr_t*)(buf + eh->e_phoff);
	*entry = eh->e_entry;
	assert(size >= eh->e_phoff + eh->e_phnum * sizeof(*ph));
	for (unsigned i = 0; i < eh->e_phnum; i++) {
	//for (unsigned i = eh->e_phnum-1; i >=0; --i) {
		if (ph[i].p_type == P_TYPE::PT_LOAD && ph[i].p_memsz) {
			if (ph[i].p_filesz) {
				assert(size >= ph[i].p_offset + ph[i].p_filesz);
				memif->write(ph[i].p_paddr, ph[i].p_filesz, (uint8_t*)((buf + eh->e_phoff + (eh->e_phentsize * eh->e_phnum)) + ph[i].p_offset));
				//memif->write(ph[i].p_paddr, ph[i].p_filesz, (uint8_t*)(buf + ph[i].p_offset));
			}
			int sz = (int)(ph[i].p_memsz - ph[i].p_filesz);
			if (0 < sz) zeros.resize(sz);
			if (0 < zeros.size()) memif->write(ph[i].p_paddr + ph[i].p_filesz, sz, &zeros[0]);
		}
	}
	shdr_t* sh = (shdr_t*)(buf + eh->e_shoff);
	assert(size >= eh->e_shoff + eh->e_shnum * sizeof(*sh));
	assert(eh->e_shstrndx < eh->e_shnum);
	assert(size >= sh[eh->e_shstrndx].sh_offset + sh[eh->e_shstrndx].sh_size);
	char *shstrtab = buf + sh[eh->e_shstrndx].sh_offset;
	unsigned strtabidx = 0, symtabidx = 0;
	for (unsigned i = 0; i < eh->e_shnum; i++) {
		uint64_t max_len = sh[eh->e_shstrndx].sh_size - (uint64_t)sh[i].sh_name;
		assert((int)sh[i].sh_name < sh[eh->e_shstrndx].sh_size);
		assert(strnlen(shstrtab + (int)sh[i].sh_name, max_len) < max_len);
		if ((int)sh[i].sh_type & (int)SH_TYPE::SHT_NOBITS) continue;
		assert(size >= sh[i].sh_offset + sh[i].sh_size);
		if (strcmp(shstrtab + (int)sh[i].sh_name, ".strtab") == 0)
			strtabidx = i;
		if (strcmp(shstrtab + (int)sh[i].sh_name, ".symtab") == 0)
			symtabidx = i;
	}
	if (strtabidx && symtabidx) {
		char* strtab = buf + sh[strtabidx].sh_offset;
		sym_t* sym = (sym_t*)(buf + sh[symtabidx].sh_offset);
		for (unsigned i = 0; i < sh[symtabidx].sh_size / sizeof(sym_t); i++) {
			uint64_t max_len = sh[strtabidx].sh_size - sym[i].st_name;
			assert(sym[i].st_name < sh[strtabidx].sh_size);
			assert(strnlen(strtab + sym[i].st_name, max_len) < max_len);
			symbols[strtab + sym[i].st_name] = sym[i].st_value;
		}
	}
}

std::map<std::string, uint64_t> load_elf(const char* fn, memif_t* memif, reg_t* entry)
{
	struct stat s;
	if (stat(fn, &s) < 0) { printf("<ERROR> fstat\n"); while (true); }
	size_t size = s.st_size;

	HANDLE hFile = CreateFile(TEXT(fn), GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_READONLY, NULL);
	if (hFile == NULL) { printf("<ERROR> CreateFile\n"); while (true); }

	HANDLE hFMO = CreateFileMapping(hFile, NULL, PAGE_READONLY, 0, 0, NULL);
	if (hFMO == NULL) { printf("<ERROR> CreateFileMapping\n"); while (true); }

	char* buf = (char*)MapViewOfFile(hFMO, FILE_MAP_READ, 0, 0, 0);
	printf("%s", buf);

	assert(size >= sizeof(Elf64_Ehdr));
	const Elf64_Ehdr* eh64 = (const Elf64_Ehdr*)buf;
	assert(IS_ELF32(*eh64) || IS_ELF64(*eh64));

	std::vector<uint8_t> zeros;
	std::map<std::string, uint64_t> symbols;

	if (IS_ELF32(*eh64))
		LOAD_ELF<Elf32_Ehdr, Elf32_Phdr, Elf32_Shdr, Elf32_Sym>(memif, entry, buf, size, zeros, symbols);
	else
		LOAD_ELF<Elf64_Ehdr, Elf64_Phdr, Elf64_Shdr, Elf64_Sym>(memif, entry, buf, size, zeros, symbols);

	CloseHandle(hFMO);
	CloseHandle(hFile);

	return symbols;
}

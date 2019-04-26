#include "elf/elf-file.h"
#include "elf/elf-format.h"
#include "instruction.h"
#include <iostream>
#include <vector>
#include <cstdint>
#include <bitset>

int main() {
	elf_file elf("hello.elf");
	std::vector<uint32_t> insts;

	for (auto& s : elf.sections) {
		if (".text" == s.name) {
			int inst_buf_size = (int)(s.buf.size() / 4);
			uint32_t* inst_buf = (uint32_t*)s.buf.data();
			insts.reserve(inst_buf_size);
			for (int i = 0; i < inst_buf_size; ++i) {
				insts.push_back(inst_buf[i]);
			}
			break;
		}
	}

	int count = 0;
	for (auto& i : insts) {
		std::cout << "[Cycle]: " << ++count << ", " << Instruction(i) << "\n";;
	}
	
	system("Pause");
	return 0;
}
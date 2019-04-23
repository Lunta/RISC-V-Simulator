#pragma once
#include <Windows.h>
#include <cstdint>
#include <cassert>
#include <vector>
#include <string>

// ELF Note Header (PT_NOTE)
// Elf32_Nhdr
typedef struct {
	uint32_t n_namesz;             /* Name size */
	uint32_t n_descsz;             /* Content size */
	uint32_t n_type;               /* Content type */
} Elf32_Nhdr;

// Elf64_Nhdr
typedef struct {
	uint32_t n_namesz;             /* Name size */
	uint32_t n_descsz;             /* Content size */
	uint32_t n_type;               /* Content type */
} Elf64_Nhdr;


enum eE_IDENT_IDX {
	  EI_MAG0	= 0		// File identification
	, EI_MAG1	= 1		// File identification
	, EI_MAG2	= 2		// File identification
	, EI_MAG3	= 3		// File identification
	, EI_CLASS	= 4		// File class
	, EI_DATA	= 5		// Data encoding
	, EI_VERSION = 6	// File version
	, EI_OSABI	= 7		// Operating system / ABI identification
	, EI_ABIVERSION	= 8	// ABI version
	, EI_PAD	= 9		// Start of padding bytes
	, EI_NIDENT	= 16	// Size of e_ident[]
};

enum class eEI_MAG : uint8_t {
	  ELFMAG0 = 0x7f	// e_ident[EI_MAG0]
	, ELFMAG1 = 'E'		// e_ident[EI_MAG1]
	, ELFMAG2 = 'L'		// e_ident[EI_MAG2]
	, ELFMAG3 = 'F'		// e_ident[EI_MAG3]
};

enum class eEI_CLASS : uint8_t {
	  ELFCLASSNONE = 0	// Invalid class
	, ELFCLASS32 = 1	// 32 - bit objects
	, ELFCLASS64 = 2	// 64 - bit objects
	, ELFCLASS128 = 3   // 128- bit objects
};

enum class eEI_DATA : uint8_t {
	  ELFDATANONE = 0	// Invalid data encoding
	, ELFDATA2LSB = 1	// 빅 엔디안
	, ELFDATA2MSB = 2	// 리틀 엔디안
};

enum class eEI_OSABI : uint8_t {
	ELFOSABI_SYSV = 0,               /* e_ident[EI_OSABI] == ELFOSABI_SYSV */
	ELFOSABI_LINUX = 3,              /* e_ident[EI_OSABI] == ELFOSABI_LINUX */
	ELFOSABI_SOLARIS = 6,            /* e_ident[EI_OSABI] == ELFOSABI_SOLARIS */
	ELFOSABI_FREEBSD = 9             /* e_ident[EI_OSABI] == ELFOSABI_FREEBSD */
};

enum class eEI_ABIVERSION : uint8_t {
	ELFABIVERSION_NONE = 0
};

struct E_IDENT {
	union {
		uint8_t  e_ident[16];
		struct {
			eEI_MAG e_mag[4];
			eEI_CLASS e_class;
			eEI_DATA e_data;
			uint8_t e_ver;
			eEI_OSABI e_os_abi;
			eEI_ABIVERSION e_abi_version;
			uint8_t e_reserved[7];
		};
	};
};

template <class Ehdr>
constexpr bool IS_ELF(const Ehdr& hdr) {
	return (hdr.e_mag[EI_MAG0] == eEI_MAG::ELFMAG0
		&& hdr.e_mag[EI_MAG1] == eEI_MAG::ELFMAG1
		&& hdr.e_mag[EI_MAG2] == eEI_MAG::ELFMAG2
		&& hdr.e_mag[EI_MAG3] == eEI_MAG::ELFMAG3);
}

template <class Ehdr>
constexpr bool IS_ELF32(const Ehdr& hdr) { return (IS_ELF(hdr) && (hdr.e_class == eEI_CLASS::ELFCLASS32)); }
template <class Ehdr>											  									  
constexpr bool IS_ELF64(const Ehdr& hdr) { return (IS_ELF(hdr) && (hdr.e_class == eEI_CLASS::ELFCLASS64)); }

enum class E_TYPE : uint16_t {
	  ET_NONE = 0			// No file type
	, ET_REL = 1			// Relocatable file
	, ET_EXEC = 2			// Executable file
	, ET_DYN = 3			// Shared object file
	, ET_CORE = 4			// Core file
	, ET_LOOS = 0xfe00		// Operating system - specific
	, ET_HIOS = 0xfeff		// Operating system - specific
	, ET_LOPROC = 0xff00	// Processor - specific
	, ET_HIPROC = 0xffff	// Processor - specific
};

enum class E_MACHINE : uint16_t {
	  EM_NONE = 0			// No machine
	, EM_M32 = 1			// AT&T WE 32100
	, EM_SPARC = 2			// SPARC
	, EM_386 = 3			// Intel 80386
	, EM_68K = 4			// Motorola 68000
	, EM_88K = 5			// Motorola 88000
	, RESERVED0 = 6			// Reserved for future use
	, EM_860 = 7			// Intel 80860
	, EM_MIPS = 8			// MIPS I Architecture
	, EM_S370 = 9			// IBM System/370 Processor
	, EM_MIPS_RS3_LE = 10	// MIPS RS3000 Little-endian
	, RESERVED1 = 11		// Reserved for future use
	, RESERVED2 = 12		// Reserved for future use
	, RESERVED3 = 13		// Reserved for future use
	, RESERVED4 = 14		// Reserved for future use
	, EM_PARISC = 15		// Hewlett-Packard PA-RISC
	, RESERVED5 = 16		// Reserved for future use
	, EM_VPP500 = 17		// Fujitsu VPP500
	, EM_SPARC32PLUS = 18	// Enhanced instruction set SPARC
	, EM_960 = 19			// Intel 80960
	, EM_PPC = 20			// PowerPC
	, EM_PPC64 = 21			// 64-bit PowerPC
	, RESERVED6 = 22		// Reserved for future use
	, RESERVED7 = 23		// Reserved for future use
	, RESERVED8 = 24		// Reserved for future use
	, RESERVED9 = 25		// Reserved for future use
	, RESERVED10 = 26		// Reserved for future use
	, RESERVED11 = 27		// Reserved for future use
	, RESERVED12 = 28		// Reserved for future use
	, RESERVED13 = 29		// Reserved for future use
	, RESERVED14 = 30		// Reserved for future use
	, RESERVED15 = 31		// Reserved for future use
	, RESERVED16 = 32		// Reserved for future use
	, RESERVED17 = 33		// Reserved for future use
	, RESERVED18 = 34		// Reserved for future use
	, RESERVED19 = 35		// Reserved for future use
	, EM_V800 = 36			// NEC V800
	, EM_FR20 = 37			// Fujitsu FR20
	, EM_RH32 = 38			// TRW RH-32
	, EM_RCE = 39			// Motorola RCE
	, EM_ARM = 40			// Advanced RISC Machines ARM
	, EM_ALPHA = 41			// Digital Alpha
	, EM_SH = 42			//	Hitachi SH
	, EM_SPARCV9 = 43		// SPARC Version 9
	, EM_TRICORE = 44		// Siemens Tricore embedded processor
	, EM_ARC = 45			// Argonaut RISC Core, Argonaut Technologies Inc.
	, EM_H8_300 = 46		// Hitachi H8/300
	, EM_H8_300H = 47		// Hitachi H8/300H
	, EM_H8S = 48			// Hitachi H8S
	, EM_H8_500 = 49		// Hitachi H8/500
	, EM_IA_64 = 50			// Intel IA-64 processor architecture
	, EM_MIPS_X = 51		// Stanford MIPS-X
	, EM_COLDFIRE = 52		// Motorola ColdFire
	, EM_68HC12 = 53		// Motorola M68HC12
	, EM_MMA = 54			// Fujitsu MMA Multimedia Accelerator
	, EM_PCP = 55			// Siemens PCP
	, EM_NCPU = 56			// Sony nCPU embedded RISC processor
	, EM_NDR1 = 57			// Denso NDR1 microprocessor
	, EM_STARCORE = 58		// Motorola Star*Core processor
	, EM_ME16 = 59			// Toyota ME16 processor
	, EM_ST100 = 60			// STMicroelectronics ST100 processor
	, EM_TINYJ = 61			// Advanced Logic Corp. TinyJ embedded processor family
	, Reserved20 = 62		// Reserved for future use
	, Reserved21 = 63		// Reserved for future use
	, Reserved22 = 64		// Reserved for future use
	, Reserved23 = 65		// Reserved for future use
	, EM_FX66 = 66			// Siemens FX66 microcontroller
	, EM_ST9PLUS = 67		// STMicroelectronics ST9+ 8/16 bit microcontroller
	, EM_ST7 = 68			// STMicroelectronics ST7 8-bit microcontroller
	, EM_68HC16 = 69		// Motorola MC68HC16 Microcontroller
	, EM_68HC11 = 70		// Motorola MC68HC11 Microcontroller
	, EM_68HC08 = 71		// Motorola MC68HC08 Microcontroller
	, EM_68HC05 = 72		// Motorola MC68HC05 Microcontroller
	, EM_SVX = 73			// Silicon Graphics SVx
	, EM_ST19 = 74			// STMicroelectronics ST19 8-bit microcontroller
	, EM_VAX = 75			// Digital VAX
	, EM_CRIS = 76			// Axis Communications 32-bit embedded processor
	, EM_JAVELIN = 77		// Infineon Technologies 32-bit embedded processor
	, EM_FIREPATH = 78		// Element 14 64-bit DSP Processor
	, EM_ZSP = 79			// LSI Logic 16-bit DSP Processor
	, EM_MMIX = 80			// Donald Knuth's educational 64-bit processor
	, EM_HUANY = 81			// Harvard University machine-independent object files
	, EM_PRISM = 82			// SiTera Prism
};

enum class E_VERSION : uint32_t {
	  EV_NONE	= 0		// Invalid version
	, EV_CURRENT = 1	// Current version
};

// ELF Section Header
enum class SH_NAME : uint32_t {
	SHN_UNDEF = 0,                   /* Used to mark an undefined or meaningless section reference */
	SHN_LOPROC = 0xff00,             /* Processor-specific use */
	SHN_HIPROC = 0xff1f,
	SHN_LOOS = 0xff20,               /* Environment-specific use */
	SHN_HIOS = 0xff3f,
	SHN_ABS = 0xfff1,                /* Indicates that the corresponding reference is an absolute value */
	SHN_COMMON = 0xfff2,             /* Indicates a symbol that has been declared as a common block */
	SHN_XINDEX = 0xffff,             /* Indicates section header has additional date in SHT_SYMTAB_SHNDX section */
	SHN_HIRESERVE = 0xffff,          /* Upper bound of the range of reserved indexes */
};

// flags entry in the first Elf32_Word of a SHT_GROUP section
enum {
	GRP_COMDAT = 0x1,
	GRP_MASKOS = 0x0ff00000,
	GRP_MASKPROC = 0xf0000000
};

enum class SH_TYPE : uint32_t {
	  SHT_NULL = 0                    /* Marks an unused section header */
	, SHT_PROGBITS = 1                /* Contains information defined by the program */
	, SHT_SYMTAB = 2                  /* Contains a linker symbol table */
	, SHT_STRTAB = 3                  /* Contains a string table */
	, SHT_RELA = 4                    /* Contains "Rela" type relocation entries */
	, SHT_HASH = 5                    /* Contains a symbol hash table */
	, SHT_DYNAMIC = 6                 /* Contains dynamic linking tables */
	, SHT_NOTE = 7                    /* Contains note information */
	, SHT_NOBITS = 8                  /* Contains uninitialized space; does not take up space in file */
	, SHT_REL = 9                     /* Contains "Rel" type relocation entries */
	, SHT_SHLIB = 10                  /* Reserved */
	, SHT_DYNSYM = 11                 /* Contains a dynamic loader symbol table */
	, SHT_INIT_ARRAY = 14             /* Contains initialization functions */
	, SHT_FINI_ARRAY = 15             /* Contains finalization functions */
	, SHT_PREINIT_ARRAY = 16          /* */
	, SHT_GROUP = 17                  /* Contains an array of Elf32_Word entries, the first entry is a flag entry */
	, SHT_SYMTAB_SHNDX = 18           /* Contains extra symbol table info, sh_link to SHT_SYMTAB with SHN_XINDEX set */
	, SHT_LOOS = 0x60000000           /* Environment-specific use */
	, SHT_GNU_VERDEF = 0x6ffffffd
	, SHT_GNU_VERNEED = 0x6ffffffe
	, SHT_GNU_VERSYM = 0x6fffffff
	, SHT_HIOS = 0x6fffffff
	, SHT_LOPROC = 0x70000000         /* Processor-specific use */
	, SHT_HIPROC = 0x7fffffff
	, SHT_LOUSER = 0x80000000         /* User-specific use */
	, SHT_HIUSER = 0xffffffff
};

enum class SH_FLAGS32 : uint32_t {
	  SHF_WRITE = 0x1				// Writable
	, SHF_ALLOC = 0x2				// Occupies memory during execution
	, SHF_EXECINSTR = 0x4			// Executable
	, SHF_MERGE = 0x10				// Might be merged
	, SHF_STRINGS = 0x20			// Contains nul-terminated strings
	, SHF_INFO_LINK = 0x40			// 'sh_info' contains SHT index
	, SHF_LINK_ORDER = 0x80			// Preserve order after combining
	, SHF_OS_NONCONFORMING = 0x100	// Non-standard OS specific handling required
	, SHF_GROUP = 0x200				// Section is member of a group
	, SHF_TLS = 0x400				// Section hold thread-local data
	, SHF_MASKOS = 0x0ff00000		// OS-specific
	, SHF_MASKPROC = 0xf0000000		// Processor-specific
	, SHF_ORDERED = 0x4000000		// Special ordering requirement (Solaris)
	, SHF_EXCLUDE = 0x8000000		// Section is excluded unless referenced or allocated (Solaris)
};
enum class SH_FLAGS64 : uint64_t {
	SHF_WRITE = 0x1				// Writable
	, SHF_ALLOC = 0x2				// Occupies memory during execution
	, SHF_EXECINSTR = 0x4			// Executable
	, SHF_MERGE = 0x10				// Might be merged
	, SHF_STRINGS = 0x20			// Contains nul-terminated strings
	, SHF_INFO_LINK = 0x40			// 'sh_info' contains SHT index
	, SHF_LINK_ORDER = 0x80			// Preserve order after combining
	, SHF_OS_NONCONFORMING = 0x100	// Non-standard OS specific handling required
	, SHF_GROUP = 0x200				// Section is member of a group
	, SHF_TLS = 0x400				// Section hold thread-local data
	, SHF_MASKOS = 0x0ff00000		// OS-specific
	, SHF_MASKPROC = 0xf0000000		// Processor-specific
	, SHF_ORDERED = 0x4000000		// Special ordering requirement (Solaris)
	, SHF_EXCLUDE = 0x8000000		// Section is excluded unless referenced or allocated (Solaris)
};

enum class P_TYPE : uint32_t {
	  PT_NULL = 0
	, PT_LOAD = 1 					// 로드된 프로그램 세그먼트
	, PT_DYNAMIC = 2 				// 동적 링크 정보
	, PT_INTERP = 3 				// 인터프리터 호출을 위한 내용
	, PT_NOTE = 4 					// 추가 정보의 위치와 크기
	, PT_SHLIB = 5
	, PT_PHDR = 6 					// 헤더 테이블 자신의 위치와 크기
	, PT_TLS = 7 					// 스레드 지역 저장소
	, PT_LOOS = 0x60000000          /* Environment-specific use */
	, PT_GNU_EH_FRAME = 0x6474e550  /* GCC .eh_frame_hdr segment */
	, PT_GNU_STACK = 0x6474e551     /* GCC stack executability */
	, PT_GNU_RELRO = 0x6474e552     /* GCC Read-only after relocation */
	, PT_HIOS = 0x6fffffff
	, PT_LOPROC = 0x70000000        /* Processor-specific use */
	, PT_HIPROC = 0x7fffffff
};

enum class P_FLAGS : uint32_t {
	  PF_X			= 0x1			// Execute
	, PF_W			= 0x2			// Write
	, PF_R			= 0x4			// Read
	, PF_MASKOS		= 0x0ff00000	// Unspecified
	, PF_MASKPROC	= 0xf0000000	// Unspecified
};


// st_info bind
enum {
	STB_LOCAL = 0,                   /* Not visible outside the object file */
	STB_GLOBAL = 1,                  /* Global symbol, visible to all object files */
	STB_WEAK = 2,                    /* Global scope, but with lower precedence than global symbols */
	STB_LOOS = 10,                   /* Environment-specific use */
	STB_HIOS = 12,
	STB_LOPROC = 13,                 /* Processor-specific use */
	STB_HIPROC = 15
};

// st_info type
enum {
	STT_NOTYPE = 0,                  /* No type specified (e.g., an absolute symbol) */
	STT_OBJECT = 1,                  /* Data object */
	STT_FUNC = 2,                    /* Function entry point */
	STT_SECTION = 3,                 /* Symbol is associated with a section */
	STT_FILE = 4,                    /* Source file associated with the object file */
	STT_LOOS = 10,                   /* Environment-specific use */
	STT_HIOS = 12,
	STT_LOPROC = 13,                 /* Processor-specific use */
	STT_HIPROC = 15
};

// st_other visibility
enum {
	STV_DEFAULT = 0,
	STV_INTERNAL = 1,
	STV_HIDDEN = 2,
	STV_PROTECTED = 3
};

inline constexpr uint8_t GET_ST_BIND(uint32_t i) { return i >> 4; }
inline constexpr uint8_t GET_ST_TYPE(uint32_t i) { return i & 0xf; }
inline constexpr uint8_t GET_ST_INFO(uint32_t b, uint32_t t) { return (b << 4) | (t & 0xf); }

typedef struct {
	union {
		uint8_t  e_ident[16];	// Magic number and other info - 0x7f 45 4c 46 01(32bit) 01(엔디안) (ELF버전) (OS정보) (App binary interface) ...
		struct {
			eEI_MAG e_mag[4];
			eEI_CLASS e_class;
			eEI_DATA e_data;
			uint8_t e_ver;
			eEI_OSABI e_os_abi;
			eEI_ABIVERSION e_abi_version;
			uint8_t e_reserved[7];
		};
	};
	E_TYPE	 e_type;		// Object file type					
	E_MACHINE e_machine;	// CPU architecture					
	E_VERSION e_version;	// Object file version				
	uint32_t e_entry;		// Entry point virtual address		
	uint32_t e_phoff;		// Program header table file offset	
	uint32_t e_shoff;		// Section header table file offset
	uint32_t e_flags;		// Processor-specific flags
	uint16_t e_ehsize;		// ELF header size in bytes
	uint16_t e_phentsize;	// Program header table entry size
	uint16_t e_phnum;		// Program header table entry count
	uint16_t e_shentsize;	// Section header table entry size
	uint16_t e_shnum;		// Section header table entry count
	uint16_t e_shstrndx;	// Section header string table index
} Elf32_Ehdr;

typedef struct {									
	SH_NAME	 sh_name;		// Section name (string tbl index)	
	SH_TYPE	 sh_type;		// Section type						
	SH_FLAGS32 sh_flags;		// Section flags					
	uint32_t sh_addr;		// Section virtual addr at execution
	uint32_t sh_offset;		// Section file offset				
	uint32_t sh_size;		// Section size in bytes			
	uint32_t sh_link;		// Link to another section 			
	uint32_t sh_info;		// Additional section information	
	uint32_t sh_addralign;	// Section alignment				
	uint32_t sh_entsize;	// Entry size if section holds table
} Elf32_Shdr;							


typedef struct {
	P_TYPE	 p_type;		// Segment type			
	uint32_t p_offset;		// Segment file offset	
	uint32_t p_vaddr;		// Segment virtual address
	uint32_t p_paddr;		// Segment physical address
	uint32_t p_filesz;		// Segment size in file	
	uint32_t p_memsz;		// Segment size in memory
	P_FLAGS p_flags;		// Segment flags		
	uint32_t p_align;		// Segment alignment	
} Elf32_Phdr;

typedef struct {
	uint32_t st_name;
	uint32_t st_value;
	uint32_t st_size;
	uint8_t  st_info;
	uint8_t  st_other;
	uint16_t st_shndx;
} Elf32_Sym;

typedef struct {
	union {
		uint8_t  e_ident[16];	// Magic number and other info - 0x7f 45 4c 46 01(32bit) 01(엔디안) (ELF버전) (OS정보) (App binary interface) ...
		struct {
			eEI_MAG e_mag[4];
			eEI_CLASS e_class;
			eEI_DATA e_data;
			uint8_t e_ver;
			eEI_OSABI e_os_abi;
			eEI_ABIVERSION e_abi_version;
			uint8_t e_reserved[7];
		};
	};
	E_TYPE	 e_type;		// Object file type
	E_MACHINE e_machine;	// CPU architecture
	E_VERSION e_version;		// Object file version
	uint64_t e_entry;		// Entry point virtual address
	uint64_t e_phoff;		// Program header table file offset
	uint64_t e_shoff;		// Section header table file offset
	uint32_t e_flags;		// Processor-specific flags
	uint16_t e_ehsize;		// ELF header size in bytes
	uint16_t e_phentsize;	// Program header table entry size
	uint16_t e_phnum;		// Program header table entry count
	uint16_t e_shentsize;	// Section header table entry size
	uint16_t e_shnum;		// Section header table entry count
	uint16_t e_shstrndx;	// Section header string table index
} Elf64_Ehdr;

typedef struct {
	SH_NAME  sh_name;		// Section name (string tbl index)
	SH_TYPE	 sh_type;		// Section type
	SH_FLAGS64 sh_flags;	// Section flags
	uint64_t sh_addr;		// Section virtual addr at execution
	uint64_t sh_offset;		// Section file offset
	uint64_t sh_size;		// Section size in bytes
	uint32_t sh_link;		// Link to another section 
	uint32_t sh_info;		// Additional section information
	uint64_t sh_addralign;	// Section alignment
	uint64_t sh_entsize;	// Entry size if section holds table
} Elf64_Shdr;

typedef struct {
	P_TYPE	 p_type;		// Segment type
	P_FLAGS p_flags;		// Segment flags
	uint64_t p_offset;		// Segment file offset		
	uint64_t p_vaddr;		// Segment virtual address
	uint64_t p_paddr;		// Segment physical address
	uint64_t p_filesz;		// Segment size in file
	uint64_t p_memsz;		// Segment size in memory
	uint64_t p_align;		// Segment alignment
} Elf64_Phdr;

typedef struct {
	uint32_t st_name;
	uint8_t  st_info;
	uint8_t  st_other;
	uint16_t st_shndx;
	uint64_t st_value;
	uint64_t st_size;
} Elf64_Sym;

class ELF64 {
public:
	ELF64(std::string file_path) : mhFile(NULL), mhFMO(NULL), mFileSize(0), mpFile(nullptr), mEntry(0) {
		struct stat s;
		if (0 != stat(file_path.c_str(), &s)) { printf("<ERROR> fstat\n"); while (true); }
		mFileSize = s.st_size;

		mhFile = CreateFile(TEXT(file_path.c_str()), GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_READONLY, NULL);
		if (mhFile == NULL) { printf("<ERROR> CreateFile\n"); while (true); }

		mhFMO = CreateFileMapping(mhFile, NULL, PAGE_READONLY, 0, 0, NULL);
		if (mhFMO == NULL) { printf("<ERROR> CreateFileMapping\n"); while (true); }

		mpFile = (uint8_t*)MapViewOfFile(mhFMO, FILE_MAP_READ, 0, 0, 0);

		mElfHeader = (Elf64_Ehdr*)mpFile;
		Elf64_Phdr* ph = (Elf64_Phdr*)(mpFile + mElfHeader->e_phoff);
		mEntry = mElfHeader->e_entry;
		assert(mFileSize >= mElfHeader->e_phoff + mElfHeader->e_phnum * sizeof(*ph));
		for (unsigned i = 0; i < mElfHeader->e_phnum; i++) {
			if (ph[i].p_type == P_TYPE::PT_LOAD && ph[i].p_memsz) {
				if (ph[i].p_filesz) {
					assert(mFileSize >= ph[i].p_offset + ph[i].p_filesz);
					memif->write(ph[i].p_paddr, ph[i].p_filesz, (uint8_t*)((mpFile + mElfHeader->e_phoff + (mElfHeader->e_phentsize * mElfHeader->e_phnum)) + ph[i].p_offset));
					//memif->write(ph[i].p_paddr, ph[i].p_filesz, (uint8_t*)(buf + ph[i].p_offset));
				}
				int sz = (int)(ph[i].p_memsz - ph[i].p_filesz);
				if (0 < sz) mZeros.resize(sz);
				if (0 < mZeros.size()) memif->write(ph[i].p_paddr + ph[i].p_filesz, sz, &mZeros[0]);
			}
		}
		Elf64_Shdr* sh = (Elf64_Shdr*)(mpFile + mElfHeader->e_shoff);
		assert(mFileSize >= mElfHeader->e_shoff + mElfHeader->e_shnum * sizeof(*sh));
		assert(mElfHeader->e_shstrndx < mElfHeader->e_shnum);
		assert(mFileSize >= sh[mElfHeader->e_shstrndx].sh_offset + sh[mElfHeader->e_shstrndx].sh_size);
		char* shstrtab = (char*)(mpFile + sh[mElfHeader->e_shstrndx].sh_offset);
		uint32_t strtabidx = 0, symtabidx = 0;
		for (unsigned i = 0; i < mElfHeader->e_shnum; i++) {
			uint64_t max_len = sh[mElfHeader->e_shstrndx].sh_size - (uint64_t)sh[i].sh_name;
			assert((int)sh[i].sh_name < sh[mElfHeader->e_shstrndx].sh_size);
			assert(strnlen(shstrtab + (int)sh[i].sh_name, max_len) < max_len);
			if ((int)sh[i].sh_type & (int)SH_TYPE::SHT_NOBITS) continue;
			assert(mFileSize >= sh[i].sh_offset + sh[i].sh_size);
			if (strcmp(shstrtab + (int)sh[i].sh_name, ".strtab") == 0)
				strtabidx = i;
			if (strcmp(shstrtab + (int)sh[i].sh_name, ".symtab") == 0)
				symtabidx = i;
		}
		if (strtabidx && symtabidx) {
			char* strtab = (char*)(mpFile + sh[strtabidx].sh_offset);
			Elf64_Sym* sym = (Elf64_Sym*)(mpFile + sh[symtabidx].sh_offset);
			for (unsigned i = 0; i < sh[symtabidx].sh_size / sizeof(Elf64_Sym); i++) {
				uint64_t max_len = sh[strtabidx].sh_size - sym[i].st_name;
				assert(sym[i].st_name < sh[strtabidx].sh_size);
				assert(strnlen(strtab + sym[i].st_name, max_len) < max_len);
				mSymbols[strtab + sym[i].st_name] = sym[i].st_value;
			}
		}

	}
	~ELF64() {
		CloseHandle(mhFMO);
		CloseHandle(mhFile);
	}

private:
	struct Segment {
		Elf64_Phdr* mHeader;
		uint8_t*	mpBody;
		size_t		mBodySize;
		Segment() : mHeader(nullptr), mpBody(nullptr), mBodySize(0) {}
	};

	struct Section {
		Elf64_Shdr* mHeader;
		uint8_t*	mpBody;
		size_t		mBodySize;
		Section() : mHeader(nullptr), mpBody(nullptr), mBodySize(0) {}
	};

private:
	HANDLE								mhFile;
	HANDLE								mhFMO;
	size_t								mFileSize;
	uint8_t*							mpFile;
	Elf64_Ehdr*							mElfHeader;
	std::vector<Segment>				mSegments;
	std::vector<Section>				mSections;
	uint64_t							mEntry;
	std::vector<uint8_t>				mZeros;
	std::map<std::string, uint64_t>		mSymbols;
};
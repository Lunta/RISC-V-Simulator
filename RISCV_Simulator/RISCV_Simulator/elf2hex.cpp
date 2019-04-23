// See LICENSE for license details.

#include <iostream>
#include "htif_hexwriter.h"
#include "memif.h"
#include "elfloader.h"

int main(int argc, char** argv)
{
	//if (argc < 4 || argc > 5)
	//{
	//	std::cerr << "Usage: " << argv[0] << " <width> <depth> <elf_file> [base]" << std::endl;
	//	return 1;
	//}

	//unsigned width = atoi(argv[1]);
	size_t width = 4;
	if (width == 0 || (width & (width - 1)))
	{
		std::cerr << "width must be a power of 2" << std::endl;
		return 1;
	}

	size_t base = 0;
	if (argc == 5) {
		base = static_cast<size_t>(atoll(argv[4]));
		if (base & (width - 1))
		{
			std::cerr << "base must be divisible by width" << std::endl;
			return 1;
		}
	}

	//unsigned depth = atoi(argv[2]);
	size_t depth = 65536 * 4; //65536;
	if (depth == 0 || (depth & (depth - 1)))
	{
		std::cerr << "depth must be a power of 2" << std::endl;
		return 1;
	}

	htif_hexwriter_t htif(base, width, depth);
	memif_t memif(&htif);
	reg_t entry;
	//load_elf(argv[3], &memif, &entry);
	auto output = load_elf("hello.elf", &memif, &entry);
	std::cout << htif;
	
	return 0;
}
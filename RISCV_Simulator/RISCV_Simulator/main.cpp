#include "RISCV_CPU.h"

int main() {
	RISCV_CPU riscv_cpu("hello.elf");

	//elf_file elf("hello.elf");
	//std::vector<Instruction> insts;
	//
	//for (auto& s : elf.sections) {
	//	if (".text" == s.name) {
	//		int inst_buf_size = (int)(s.buf.size() / 4);
	//		uint32_t* inst_buf = (uint32_t*)s.buf.data();
	//
	//		insts.reserve(inst_buf_size);
	//		for (int i = 0; i < inst_buf_size; ++i) {
	//			insts.emplace_back(inst_buf[i]);
	//		}
	//		break;
	//	}
	//}
	//
	//int count = 0;
	//for (auto& inst : insts) {
	//	std::cout << "[Cycle]: " << ++count << ", " << inst << "\n";;
	//}
	
	system("Pause");
	return 0;
}
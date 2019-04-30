#include "RISCV_CPU.h"
#include "executable_insts.h"

RISCV_CPU::RISCV_CPU(const std::string & elf_file) : m_file(elf_file.c_str())
{
	m_pc = (uint32_t)(m_file.filebuf.data() + m_file.ehdr.e_entry);
}

RISCV_CPU::~RISCV_CPU()
{
}

void RISCV_CPU::stage_inst_fecth()
{
	//m_IR = Instruction(*((uint32_t*)m_pc));
}

void RISCV_CPU::stage_inst_decode_and_reg_fecth()
{
}

void RISCV_CPU::stage_execute_and_calc_addr()
{
}

void RISCV_CPU::stage_mem_access()
{
}

void RISCV_CPU::stage_write_back()
{
}

void RISCV_CPU::run()
{
}

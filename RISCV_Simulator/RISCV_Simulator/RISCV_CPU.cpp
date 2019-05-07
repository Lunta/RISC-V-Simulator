#include "RISCV_CPU.h"
#include "executable_insts.h"

RISCV_CPU::RISCV_CPU(const std::string & elf_file) : m_file(elf_file.c_str()), m_bRun(true), m_bStall(false)
{
	m_pMem = m_file.filebuf.data();
	m_npc = m_pc = reinterpret_cast<uint32_t>(m_pMem + m_file.ehdr.e_entry);
}

RISCV_CPU::~RISCV_CPU()
{
}

RISCV_CPU_5STAGE_IN_ORDER::RISCV_CPU_5STAGE_IN_ORDER(const std::string & elf_file) : RISCV_CPU(elf_file)
{
}

RISCV_CPU_5STAGE_IN_ORDER::~RISCV_CPU_5STAGE_IN_ORDER()
{
}

void RISCV_CPU_5STAGE_IN_ORDER::run()
{
	int tick_count = 0;
	while (m_bRun) {
		// 역순인 이유: 차례대로 실행하면 루프 한번에 명령어 하나가 실행되버림
		stage_write_back();
		stage_mem_access();
		stage_execute_and_calc_addr();
		stage_inst_decode_and_reg_fecth();
		stage_inst_fecth();
		std::cout << "[Clock cycle]: " << ++tick_count 
			<< ", [PC]: " << std::hex << m_pc << std::dec
			<< ", " << Instruction(m_IR) << "\n";
	}
}

void RISCV_CPU_5STAGE_IN_ORDER::stage_inst_fecth()
{
	if (true == m_bStall) {
		m_IR = 0;
	}
	else {
		m_npc = m_pc + 4;
		m_IR = *reinterpret_cast<uint32_t*>(m_pc);
	}
}

void RISCV_CPU_5STAGE_IN_ORDER::stage_inst_decode_and_reg_fecth()
{
	m_decode_inst = Instruction(m_IR);
	switch (m_decode_inst.m_type) {
	case InstType::JAL:
		m_reg.x[m_decode_inst.m_rd] = m_npc;
		m_npc = static_cast<uint32_t>((int32_t)m_pc + m_decode_inst.m_imm.s32);
		m_bStall = true;
		break;
	default:
		m_pc = m_npc;
		break;
	}
}

void RISCV_CPU_5STAGE_IN_ORDER::stage_execute_and_calc_addr()
{
	m_execute_inst = m_decode_inst;
	switch (m_execute_inst.m_type) {
	case InstType::JAL:
		m_pc = m_npc;
		m_execute_inst = Instruction();
		m_bStall = false;
		break;
	default:
		break;
	}
}

void RISCV_CPU_5STAGE_IN_ORDER::stage_mem_access()
{
	m_mem_access_inst = m_execute_inst;
	switch (m_mem_access_inst.m_type) {
	case InstType::JAL:
		break;
	default:
		break;
	}
}

void RISCV_CPU_5STAGE_IN_ORDER::stage_write_back()
{
	m_write_back_inst = m_mem_access_inst;
	switch (m_write_back_inst.m_type) {
	case InstType::JAL:
		break;
	default:
		break;
	}
}

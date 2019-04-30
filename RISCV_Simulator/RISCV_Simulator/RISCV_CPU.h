#pragma once
#include "common.h"

#include "elf/elf-file.h"
#include "elf/elf-format.h"
#include "instruction.h"
#include "register.h"

class RISCV_CPU {
public:
	RISCV_CPU(const std::string& elf_file);
	~RISCV_CPU();

	void run();

private:
	void stage_inst_fecth();
	void stage_inst_decode_and_reg_fecth();
	void stage_execute_and_calc_addr();
	void stage_mem_access();
	void stage_write_back();

private:
	elf_file			m_file;
	uint8_t*			m_pMem;

	uint32_t			m_pc;
	uint32_t			m_npc;
	Instruction*		m_pIR;

	Register			m_reg;
};
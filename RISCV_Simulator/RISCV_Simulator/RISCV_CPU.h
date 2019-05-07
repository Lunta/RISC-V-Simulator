#pragma once
#include "common.h"

#include "elf/elf-file.h"
#include "elf/elf-format.h"
#include "instruction.h"
#include "register.h"

class RISCV_CPU {
public:
	RISCV_CPU(const std::string& elf_file);
	virtual ~RISCV_CPU();

	virtual void run() = 0;

protected:
	elf_file			m_file;
	bool				m_bRun;

	bool				m_bStall;

	uint32_t			m_pc;
	uint32_t			m_npc;
	uint32_t			m_IR;

	Instruction			m_decode_inst;
	Register			m_reg;
	uint32_t			m_reg_a;
	uint32_t			m_reg_b;

	Instruction			m_execute_inst;
	uint32_t			m_ALU_output;
	bool				m_bCondition;

	Instruction			m_mem_access_inst;
	uint8_t*			m_pMem;
	uint32_t			m_LMD;

	Instruction			m_write_back_inst;
};

class RISCV_CPU_5STAGE_IN_ORDER : public RISCV_CPU {
public:
	RISCV_CPU_5STAGE_IN_ORDER(const std::string& elf_file);
	virtual ~RISCV_CPU_5STAGE_IN_ORDER();

	virtual void run();

private:
	void stage_inst_fecth();
	void stage_inst_decode_and_reg_fecth();
	void stage_execute_and_calc_addr();
	void stage_mem_access();
	void stage_write_back();

private:
};
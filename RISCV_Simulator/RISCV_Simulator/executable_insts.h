#pragma once
#include "RISCV_CPU.h"
#include "instruction.h"

class inst_jar : public Instruction {
	virtual void stage_inst_fecth(const RISCV_CPU& riscv_cpu) {}
	virtual void stage_inst_decode_and_reg_fecth(const RISCV_CPU& riscv_cpu) {}
	virtual void stage_execute_and_calc_addr(const RISCV_CPU& riscv_cpu) {}
	virtual void stage_mem_access(const RISCV_CPU& riscv_cpu) {}
	virtual void stage_write_back(const RISCV_CPU& riscv_cpu) {}
};
#pragma once
#include <iostream>
#include <bitset>
#include <cstdint>
#include <string>
/*
https://content.riscv.org/wp-content/uploads/2017/05/riscv-spec-v2.2.pdf 
103p
*/

constexpr uint32_t MASK_OPCODE			= 0b00000000'00000000'00000000'01111111;
constexpr uint32_t MASK_REGISTER_DEST	= 0b00000000'00000000'00001111'10000000;
constexpr uint32_t MASK_FUNCT3			= 0b00000000'00000000'01110000'00000000;
constexpr uint32_t MASK_REGISTER_SRC1	= 0b00000000'00001111'10000000'00000000;
constexpr uint32_t MASK_REGISTER_SRC2	= 0b00000001'11110000'00000000'00000000;
constexpr uint32_t MASK_FUNCT7			= 0b11111110'00000000'00000000'00000000;
constexpr uint32_t MASK_REGISTER_SRC3	= 0b11111000'00000000'00000000'00000000;
constexpr uint32_t MASK_FUNCT2			= 0b00000110'00000000'00000000'00000000;
constexpr uint32_t MASK_IMM_U_31_12		= 0b11111111'11111111'11110000'00000000;
constexpr uint32_t MASK_IMM_J_20		= 0b10000000'00000000'00000000'00000000;
constexpr uint32_t MASK_IMM_J_10_1		= 0b01111111'11100000'00000000'00000000;
constexpr uint32_t MASK_IMM_J_11		= 0b00000000'00010000'00000000'00000000;
constexpr uint32_t MASK_IMM_J_19_12		= 0b00000000'00001111'11110000'00000000;
constexpr uint32_t MASK_IMM_I_11_0		= 0b11111111'11110000'00000000'00000000;
constexpr uint32_t MASK_IMM_S_11_5		= 0b11111110'00000000'00000000'00000000;
constexpr uint32_t MASK_IMM_S_4_0		= 0b00000000'00000000'00001111'10000000;
constexpr uint32_t MASK_IMM_B_12		= 0b10000000'00000000'00000000'00000000;
constexpr uint32_t MASK_IMM_B_10_5		= 0b01111110'00000000'00000000'00000000;
constexpr uint32_t MASK_IMM_B_4_1		= 0b00000000'00000000'00001111'00000000;
constexpr uint32_t MASK_IMM_B_11		= 0b00000000'00000000'00000000'10000000;

constexpr uint32_t BIT_OFFSET_OPCODE		= 0;
constexpr uint32_t BIT_OFFSET_REGISTER_DEST	= 7;
constexpr uint32_t BIT_OFFSET_FUNCT3		= 12;
constexpr uint32_t BIT_OFFSET_REGISTER_SRC1	= 15;
constexpr uint32_t BIT_OFFSET_REGISTER_SRC2	= 20;
constexpr uint32_t BIT_OFFSET_FUNCT7		= 25;
constexpr uint32_t BIT_OFFSET_REGISTER_SRC3 = 27;
constexpr uint32_t BIT_OFFSET_FUNCT2		= 25;
constexpr uint32_t BIT_OFFSET_IMM_U_31_12	= 12;
constexpr uint32_t BIT_OFFSET_IMM_J_20		= 31;
constexpr uint32_t BIT_OFFSET_IMM_J_10_1	= 21;
constexpr uint32_t BIT_OFFSET_IMM_J_11		= 20;
constexpr uint32_t BIT_OFFSET_IMM_J_19_12	= 12;
constexpr uint32_t BIT_OFFSET_IMM_I_11_0	= 20;
constexpr uint32_t BIT_OFFSET_IMM_S_11_5	= 25;
constexpr uint32_t BIT_OFFSET_IMM_S_4_0		= 7;
constexpr uint32_t BIT_OFFSET_IMM_B_12		= 31;
constexpr uint32_t BIT_OFFSET_IMM_B_10_5	= 25;
constexpr uint32_t BIT_OFFSET_IMM_B_4_1		= 8;
constexpr uint32_t BIT_OFFSET_IMM_B_11		= 7;

constexpr uint32_t BIT_ALIGN_MASK_OPCODE			= 0b00000000'00000000'01111111;
constexpr uint32_t BIT_ALIGN_MASK_REGISTER_DEST		= 0b00000000'00000000'00011111;
constexpr uint32_t BIT_ALIGN_MASK_FUNCT3			= 0b00000000'00000000'00000111;
constexpr uint32_t BIT_ALIGN_MASK_REGISTER_SRC1		= 0b00000000'00000000'00011111;
constexpr uint32_t BIT_ALIGN_MASK_REGISTER_SRC2		= 0b00000000'00000000'00011111;
constexpr uint32_t BIT_ALIGN_MASK_FUNCT7			= 0b00000000'00000000'01111111;
constexpr uint32_t BIT_ALIGN_MASK_REGISTER_SRC3		= 0b00000000'00000000'00011111;
constexpr uint32_t BIT_ALIGN_MASK_FUNCT2			= 0b00000000'00000000'00000011;
constexpr uint32_t BIT_ALIGN_MASK_IMM_U_31_12		= 0b00001111'11111111'11111111;
constexpr uint32_t BIT_ALIGN_MASK_IMM_J_20			= 0b00000000'00000000'00000001;
constexpr uint32_t BIT_ALIGN_MASK_IMM_J_10_1		= 0b00000000'00000011'11111111;
constexpr uint32_t BIT_ALIGN_MASK_IMM_J_11			= 0b00000000'00000000'00000001;
constexpr uint32_t BIT_ALIGN_MASK_IMM_J_19_12		= 0b00000000'00000000'11111111;
constexpr uint32_t BIT_ALIGN_MASK_IMM_I_11_0		= 0b00000000'00001111'11111111;
constexpr uint32_t BIT_ALIGN_MASK_IMM_I_11_0_SIGN	= 0b00000000'00001000'00000000;
constexpr uint32_t BIT_ALIGN_MASK_IMM_S_11_5		= 0b00000000'00000000'01111111;
constexpr uint32_t BIT_ALIGN_MASK_IMM_S_4_0			= 0b00000000'00000000'00011111;
constexpr uint32_t BIT_ALIGN_MASK_IMM_B_12			= 0b00000000'00000000'00000001;
constexpr uint32_t BIT_ALIGN_MASK_IMM_B_10_5		= 0b00000000'00000000'00111111;
constexpr uint32_t BIT_ALIGN_MASK_IMM_B_4_1			= 0b00000000'00000000'00001111;
constexpr uint32_t BIT_ALIGN_MASK_IMM_B_11			= 0b00000000'00000000'00000001;

enum class InstFormat : uint8_t { INVALID, R_TYPE, R4_TYPE, I_TYPE, S_TYPE, B_TYPE, U_TYPE, J_TYPE };

enum class InstType : uint8_t {
	INVALID

	// RV32I Base Inst Set
	, LUI
	, AUIPC
	, JAL
	, JALR
	, BEQ
	, BNE
	, BLT
	, BGE
	, BLTU
	, BGEU
	, LB
	, LH
	, LW
	, LBU
	, LHU
	, SB
	, SH
	, SW
	, ADDI
	, SLTI
	, SLTIU
	, XORI
	, ORI
	, ANDI
	// , SLLI
	// , SRLI
	// , SRAI
	, ADD
	, SUB
	, SLL
	, SLT
	, SLTU
	, XOR
	, SRL
	, SRA
	, OR
	, AND
	, FENCE
	, FENCE_I
	, ECALL
	, EBREAK
	, CSRRW
	, CSRRS
	, CSRRC
	, CSRRWI
	, CSRRSI
	, CSRRCI

	// RV64I Base Instruction Set(in addition to RV32I)
	, LWU
	, LD
	, SD
	, SLLI
	, SRLI
	, SRAI
	, ADDIW
	, SLLIW
	, SRLIW
	, SRAIW
	, ADDW
	, SUBW
	, SLLW
	, SRLW
	, SRAW

	// RV32M Standard Extension
	, MUL
	, MULH
	, MULHSU
	, MULHU
	, DIV
	, DIVU
	, REM
	, REMU

	// RV64M Standard Extension(in addition to RV32M)
	, MULW
	, DIVW
	, DIVUW
	, REMW
	, REMUW

	// RV32A Standard Extension
	, LR_W
	, SC_W
	, AMOSWAP_W
	, AMOADD_W
	, AMOXOR_W
	, AMOAND_W
	, AMOOR_W
	, AMOMIN_W
	, AMOMAX_W
	, AMOMINU_W
	, AMOMAXU_W

	// RV64A Standard Extension(in addition to RV32A)
	, LR_D
	, SC_D
	, AMOSWAP_D
	, AMOADD_D
	, AMOXOR_D
	, AMOAND_D
	, AMOOR_D
	, AMOMIN_D
	, AMOMAX_D
	, AMOMINU_D
	, AMOMAXU_D

	// RV32F Standard Extension
	, FLW
	, FSW
	, FMADD_S
	, FMSUB_S
	, FNMSUB_S
	, FNMADD_S
	, FADD_S
	, FSUB_S
	, FMUL_S
	, FDIV_S
	, FSQRT_S
	, FSGNJ_S
	, FSGNJN_S
	, FSGNJX_S
	, FMIN_S
	, FMAX_S
	, FCVT_W_S
	, FCVT_WU_S
	, FMV_X_W
	, FEQ_S
	, FLT_S
	, FLE_S
	, FCLASS_S
	, FCVT_S_W
	, FCVT_S_WU
	, FMV_W_X

	// RV64F Standard Extension(in addition to RV32F)
	, FCVT_L_S
	, FCVT_LU_S
	, FCVT_S_L
	, FCVT_S_LU

	// RV32D Standard Extension
	, FLD
	, FSD
	, FMADD_D
	, FMSUB_D
	, FNMSUB_D
	, FNMADD_D
	, FADD_D
	, FSUB_D
	, FMUL_D
	, FDIV_D
	, FSQRT_D
	, FSGNJ_D
	, FSGNJN_D
	, FSGNJX_D
	, FMIN_D
	, FMAX_D
	, FCVT_S_D
	, FCVT_D_S
	, FEQ_D
	, FLT_D
	, FLE_D
	, FCLASS_D
	, FCVT_W_D
	, FCVT_WU_D
	, FCVT_D_W
	, FCVT_D_WU

	// RV64D Standard Extension(in addition to RV32D)
	, FCVT_L_D
	, FCVT_LU_D
	, FMV_X_D
	, FCVT_D_L
	, FCVT_D_LU
	, FMV_D_X
};

enum class CSRType : uint8_t {
	INVALID

	// Floating-Point Control and Status Registers
	, fflags
	, frm
	, fcsr

	// Counters and Timers
	, cycle
	, time
	, instret
	, cycleh
	, timeh
	, instreth
};

constexpr InstType GetInstType(uint32_t inst);
constexpr InstFormat GetInstFormat(InstType inst_type);
std::string GetInstName(InstType inst_t);
constexpr CSRType GetCSRType(uint32_t imm_11_0);

constexpr InstType GetInstType(uint32_t inst) {
	uint32_t opcode = (inst >> BIT_OFFSET_OPCODE) & BIT_ALIGN_MASK_OPCODE;
	uint32_t funct3 = (inst >> BIT_OFFSET_FUNCT3) & BIT_ALIGN_MASK_FUNCT3;
	uint32_t funct7 = (inst >> BIT_OFFSET_FUNCT7) & BIT_ALIGN_MASK_FUNCT7;
	uint32_t imm_i_11_0 = (inst >> BIT_OFFSET_IMM_I_11_0) & BIT_ALIGN_MASK_IMM_I_11_0;
	uint32_t imm_s_11_5 = (inst >> BIT_OFFSET_IMM_S_11_5) & BIT_ALIGN_MASK_IMM_S_11_5;
	uint32_t rs2 = (inst >> BIT_OFFSET_REGISTER_SRC2) & BIT_ALIGN_MASK_REGISTER_SRC2;
	switch (opcode) {
	case 0b0110111: return InstType::LUI;
	case 0b0010111: return InstType::AUIPC;
	case 0b1101111: return InstType::JAL;
	case 0b1100111: return InstType::JALR;
	case 0b1100011: {
		switch (funct3) {
		case 0b000: return InstType::BEQ;
		case 0b001:	return InstType::BNE;
		case 0b100:	return InstType::BLT;
		case 0b101:	return InstType::BGE;
		case 0b110:	return InstType::BLTU;
		case 0b111:	return InstType::BGEU;
		}
		break;
	}
	case 0b0000011: {
		switch (funct3) {
		case 0b000: return InstType::LB;
		case 0b001:	return InstType::LH;
		case 0b010:	return InstType::LW;
		case 0b100:	return InstType::LBU;
		case 0b101:	return InstType::LHU;
		case 0b110:	return InstType::LWU;
		case 0b011:	return InstType::LD;
		}
		break;
	}
	case 0b0100011: {
		switch (funct3) {
		case 0b000: return InstType::SB;
		case 0b001:	return InstType::SH;
		case 0b010:	return InstType::SW;
		case 0b011:	return InstType::SD;
		}
		break;
	}
	case 0b0010011: {
		switch (funct3) {
		case 0b000: return InstType::ADDI;
		case 0b010:	return InstType::SLTI;
		case 0b011:	return InstType::SLTIU;
		case 0b100:	return InstType::XORI;
		case 0b111:	return InstType::ORI;
		case 0b110:	return InstType::ANDI;
		case 0b001: {
			//uint32_t imm = (imm_i_11_0 >> 7) & 0b01111111;
			uint32_t imm = (imm_i_11_0 >> 6) & 0b00111111;
			if (0b000000 == imm) return InstType::SLLI;
			//if (0b0000000 == imm) return InstType::SLLI; // rv32i
			break;
		}
		case 0b101: {
			//uint32_t imm = (imm_i_11_0 >> 7) & 0b01111111;
			uint32_t imm = (imm_i_11_0 >> 6) & 0b00111111;
			if (0b000000 == imm) return InstType::SRLI;
			if (0b010000 == imm) return InstType::SRAI;
			// if (0b0000000 == imm) return InstType::SRLI; // rv32i
			// if (0b0100000 == imm) return InstType::SRAI; // rv32i
			break;
		}
		}
		break;
	}
	case 0b0011011: {
		switch (funct3) {
		case 0b000: return InstType::ADDIW;
		case 0b001:
			if (0b0000000 == funct7) return InstType::SLLIW;
			break;
		case 0b101:
			if (0b0000000 == funct7) return InstType::SRLIW;
			if (0b0100000 == funct7) return InstType::SRAIW;
			break;
		}
		break;
	}
	case 0b0110011: {
		switch (funct3) {
		case 0b000:
			if (0b0000000 == funct7) return InstType::ADD;
			if (0b0100000 == funct7) return InstType::SUB;
			if (0b0000001 == funct7) return InstType::MUL;
			break;
		case 0b001:	
			if (0b0000000 == funct7) return InstType::SLL;
			if (0b0000001 == funct7) return InstType::MULH;
			break;
		case 0b010:	
			if (0b0000000 == funct7) return InstType::SLT;
			if (0b0000001 == funct7) return InstType::MULHSU;
			break;
		case 0b011:	
			if (0b0000000 == funct7) return InstType::SLTU;
			if (0b0000001 == funct7) return InstType::MULHU;
			break;
		case 0b100:
			if (0b0000000 == funct7) return InstType::XOR;
			if (0b0000001 == funct7) return InstType::DIV;
			break;
		case 0b101:	
			if (0b0000000 == funct7) return InstType::SRL;
			if (0b0100000 == funct7) return InstType::SRA;
			if (0b0000001 == funct7) return InstType::DIVU;
			break;
		case 0b110:
			if (0b0000000 == funct7) return InstType::OR;
			if (0b0000001 == funct7) return InstType::REM;
			break;
		case 0b111:
			if (0b0000000 == funct7) return InstType::AND;
			if (0b0000001 == funct7) return InstType::REMU;
			break;
		}
		break;
	}
	case 0b0111011: {
		switch (funct3) {
		case 0b000:
			if (0b0000000 == funct7) return InstType::ADDW;
			if (0b0100000 == funct7) return InstType::SUBW;
			if (0b0000001 == funct7) return InstType::MULW;
			break;
		case 0b001:
			if (0b0000000 == funct7) return InstType::SLLW;
			break;
		case 0b100:
			if (0b0000001 == funct7) return InstType::DIVW;
			break;
		case 0b101:
			if (0b0000000 == funct7) return InstType::SRLW;
			if (0b0100000 == funct7) return InstType::SRAW;
			if (0b0000001 == funct7) return InstType::DIVUW;
			break;
		case 0b110:
			if (0b0000001 == funct7) return InstType::REMW;
			break;
		case 0b111:
			if (0b0000001 == funct7) return InstType::REMUW;
			break;
		}
		break;
	}
	case 0b0001111: {
		switch (funct3) {
		case 0b000: return InstType::FENCE;
		case 0b001:	return InstType::FENCE_I;
		}
		break;
	}
	case 0b1110011: {
		switch (funct3) {
		case 0b000:
			if (0b00000000'00000000 == imm_i_11_0) return InstType::ECALL;
			if (0b00000000'00000001 == imm_i_11_0) return InstType::EBREAK;
			break;
		case 0b001:	return InstType::CSRRW;
		case 0b010:	return InstType::CSRRS;
		case 0b011:	return InstType::CSRRC;
		case 0b101:	return InstType::CSRRWI;
		case 0b110:	return InstType::CSRRSI;
		case 0b111:	return InstType::CSRRCI;
		}
		break;
	}
	case 0b0101111: {
		uint32_t funct5 = (funct7 >> 2) & 0b00011111;
		switch (funct3) {
		case 0b010:
			switch (funct5) {
			case 0b00010: return InstType::LR_W;
			case 0b00011: return InstType::SC_W;
			case 0b00001: return InstType::AMOSWAP_W;
			case 0b00000: return InstType::AMOADD_W;
			case 0b00100: return InstType::AMOXOR_W;
			case 0b01100: return InstType::AMOAND_W;
			case 0b01000: return InstType::AMOOR_W;
			case 0b10000: return InstType::AMOMIN_W;
			case 0b10100: return InstType::AMOMAX_W;
			case 0b11000: return InstType::AMOMINU_W;
			case 0b11100: return InstType::AMOMAXU_W;
			}
			break;
		case 0b011:
			switch (funct5) {
			case 0b00010: return InstType::LR_D;
			case 0b00011: return InstType::SC_D;
			case 0b00001: return InstType::AMOSWAP_D;
			case 0b00000: return InstType::AMOADD_D;
			case 0b00100: return InstType::AMOXOR_D;
			case 0b01100: return InstType::AMOAND_D;
			case 0b01000: return InstType::AMOOR_D;
			case 0b10000: return InstType::AMOMIN_D;
			case 0b10100: return InstType::AMOMAX_D;
			case 0b11000: return InstType::AMOMINU_D;
			case 0b11100: return InstType::AMOMAXU_D;
			}
			break;
		}
		break;
	}
	case 0b0000111: {
		switch (funct3) {
		case 0b010: return InstType::FLW;
		case 0b011:	return InstType::FLD;
		}
		break;
	}
	case 0b0100111: {
		switch (funct3) {
		case 0b010: return InstType::FSW;
		case 0b011:	return InstType::FSD;
		}
		break;
	}
	case 0b1000011: {
		uint32_t funct2 = (inst >> BIT_OFFSET_FUNCT2) & BIT_ALIGN_MASK_FUNCT2;
		switch (funct2) {
		case 0b00: return InstType::FMADD_S;
		case 0b01: return InstType::FMADD_D;
		}
		break;
	}
	case 0b1000111: {
		uint32_t funct2 = (inst >> BIT_OFFSET_FUNCT2) & BIT_ALIGN_MASK_FUNCT2;
		switch (funct2) {
		case 0b00: return InstType::FMSUB_S;
		case 0b01: return InstType::FMSUB_D;
		}
		break;
	}
	case 0b1001011: {
		uint32_t funct2 = (inst >> BIT_OFFSET_FUNCT2) & BIT_ALIGN_MASK_FUNCT2;
		switch (funct2) {
		case 0b00: return InstType::FNMSUB_S;
		case 0b01: return InstType::FNMSUB_D;
		}
		break;
	}
	case 0b1001111: {
		uint32_t funct2 = (inst >> BIT_OFFSET_FUNCT2) & BIT_ALIGN_MASK_FUNCT2;
		switch (funct2) {
		case 0b00: return InstType::FNMADD_S;
		case 0b01: return InstType::FNMADD_D;
		}
		break;
	}
	case 0b1010011: {
		switch (funct7) {
		case 0b0000000: return InstType::FADD_S;
		case 0b0000001: return InstType::FADD_D;
		case 0b0000100:	return InstType::FSUB_S;
		case 0b0000101:	return InstType::FSUB_D;
		case 0b0001000:	return InstType::FMUL_S;
		case 0b0001001:	return InstType::FMUL_D;
		case 0b0001100:	return InstType::FDIV_S;
		case 0b0001101:	return InstType::FDIV_D;
		case 0b0101100:	return InstType::FSQRT_S;
		case 0b0101101:	return InstType::FSQRT_D;
		case 0b0010000:	
			switch (funct3) {
			case 0b000: return InstType::FSGNJ_S;
			case 0b001:	return InstType::FSGNJN_S;
			case 0b010:	return InstType::FSGNJX_S;
			}
			break;
		case 0b0010001:
			switch (funct3) {
			case 0b000: return InstType::FSGNJ_D;
			case 0b001:	return InstType::FSGNJN_D;
			case 0b010:	return InstType::FSGNJX_D;
			}
			break;
		case 0b0010100:	
			switch (funct3) {
			case 0b000: return InstType::FMIN_S;
			case 0b001:	return InstType::FMAX_S;
			}
			break;
		case 0b0010101:
			switch (funct3) {
			case 0b000: return InstType::FMIN_D;
			case 0b001:	return InstType::FMAX_D;
			}
			break;
		case 0b0100000:
			if (0b00001 == rs2) return InstType::FCVT_S_D;
			break;
		case 0b0100001:
			if (0b00000 == rs2) return InstType::FCVT_D_S;
			break;
		case 0b1100000: 
			switch (rs2) {
			case 0b00000: return InstType::FCVT_W_S;
			case 0b00001: return InstType::FCVT_WU_S;
			case 0b00010: return InstType::FCVT_L_S;
			case 0b00011: return InstType::FCVT_LU_S;
			}
			break;
		case 0b1100001:
			switch (rs2) {
			case 0b00000: return InstType::FCVT_W_D;
			case 0b00001: return InstType::FCVT_WU_D;
			case 0b00010: return InstType::FCVT_L_D;
			case 0b00011: return InstType::FCVT_LU_D;
			}
			break;
		case 0b1110000: 
			if (0b00000 == rs2) {
				switch (funct3) {
				case 0b000: return InstType::FMV_X_W;
				case 0b001:	return InstType::FCLASS_S;
				}
			}
			break;
		case 0b1110001:
			if (0b00000 == rs2) {
				switch (funct3) {
				case 0b000: return InstType::FMV_X_D;
				case 0b001:	return InstType::FCLASS_D;
				}
			}
			break;
		case 0b1010000:
			switch (funct3) {
			case 0b010:	return InstType::FEQ_S;
			case 0b001:	return InstType::FLT_S;
			case 0b000: return InstType::FLE_S;
			}
			break;
		case 0b1010001:
			switch (funct3) {
			case 0b010:	return InstType::FEQ_D;
			case 0b001:	return InstType::FLT_D;
			case 0b000: return InstType::FLE_D;
			}
			break;
		case 0b1101000: 
			switch (rs2) {
			case 0b00000: return InstType::FCVT_S_W;
			case 0b00001: return InstType::FCVT_S_WU;
			case 0b00010: return InstType::FCVT_S_L;
			case 0b00011: return InstType::FCVT_S_LU;
			}
			break;
		case 0b1101001:
			switch (rs2) {
			case 0b00000: return InstType::FCVT_D_W;
			case 0b00001: return InstType::FCVT_D_WU;
			case 0b00010: return InstType::FCVT_D_L;
			case 0b00011: return InstType::FCVT_D_LU;
			}
			break;
		case 0b1111000:	return InstType::FMV_W_X;
		case 0b1111001:	return InstType::FMV_D_X;
		}
		break;
	}
	default:
		std::cout << "[INVALID INSTRUCTION!]: "<< std::bitset<32>(inst) <<"\n";
		break;
	}
	return InstType::INVALID;
}

constexpr InstFormat GetInstFormat(InstType inst_type) {
	switch (inst_type) {
	// func7 | 0000000
	case InstType::ADD:
	case InstType::SUB:
	case InstType::SLL:
	case InstType::SLT:
	case InstType::SLTU:
	case InstType::XOR:
	case InstType::SRL:
	case InstType::SRA:
	case InstType::OR:
	case InstType::AND:
	case InstType::SLLIW:
	case InstType::SRLIW:
	case InstType::SRAIW:
	case InstType::ADDW:
	case InstType::SUBW:
	case InstType::SLLW:
	case InstType::SRLW:
	case InstType::SRAW:
	case InstType::MUL:
	case InstType::MULH:
	case InstType::MULHSU:
	case InstType::MULHU:
	case InstType::DIV:
	case InstType::DIVU:
	case InstType::REM:
	case InstType::REMU:
	case InstType::MULW:
	case InstType::DIVW:
	case InstType::DIVUW:
	case InstType::REMW:
	case InstType::REMUW:
	case InstType::FADD_S:
	case InstType::FSUB_S:
	case InstType::FMUL_S:
	case InstType::FDIV_S:
	case InstType::FSQRT_S:
	case InstType::FSGNJ_S:
	case InstType::FSGNJN_S:
	case InstType::FSGNJX_S:
	case InstType::FMIN_S:
	case InstType::FMAX_S:
	case InstType::FCVT_W_S:
	case InstType::FCVT_WU_S:
	case InstType::FMV_X_W:
	case InstType::FEQ_S:
	case InstType::FLT_S:
	case InstType::FLE_S:
	case InstType::FCLASS_S:
	case InstType::FCVT_S_W:
	case InstType::FCVT_S_WU:
	case InstType::FMV_W_X:
	case InstType::FCVT_L_S:
	case InstType::FCVT_LU_S:
	case InstType::FCVT_S_L:
	case InstType::FCVT_S_LU:
	case InstType::FADD_D:
	case InstType::FSUB_D:
	case InstType::FMUL_D:
	case InstType::FDIV_D:
	case InstType::FSQRT_D:
	case InstType::FSGNJ_D:
	case InstType::FSGNJN_D:
	case InstType::FSGNJX_D:
	case InstType::FMIN_D:
	case InstType::FMAX_D:
	case InstType::FCVT_S_D:
	case InstType::FCVT_D_S:
	case InstType::FEQ_D:
	case InstType::FLT_D:
	case InstType::FLE_D:
	case InstType::FCLASS_D:
	case InstType::FCVT_W_D:
	case InstType::FCVT_WU_D:
	case InstType::FCVT_D_W:
	case InstType::FCVT_D_WU:
	case InstType::FCVT_L_D:
	case InstType::FCVT_LU_D:
	case InstType::FMV_X_D:
	case InstType::FCVT_D_L:
	case InstType::FCVT_D_LU:
	case InstType::FMV_D_X:

	// func7 | 00000 aq rl
	case InstType::LR_W:
	case InstType::SC_W:
	case InstType::AMOSWAP_W:
	case InstType::AMOADD_W:
	case InstType::AMOXOR_W:
	case InstType::AMOAND_W:
	case InstType::AMOOR_W:
	case InstType::AMOMIN_W:
	case InstType::AMOMAX_W:
	case InstType::AMOMINU_W:
	case InstType::AMOMAXU_W:
	case InstType::LR_D:
	case InstType::SC_D:
	case InstType::AMOSWAP_D:
	case InstType::AMOADD_D:
	case InstType::AMOXOR_D:
	case InstType::AMOAND_D:
	case InstType::AMOOR_D:
	case InstType::AMOMIN_D:
	case InstType::AMOMAX_D:
	case InstType::AMOMINU_D:
	case InstType::AMOMAXU_D:
		return InstFormat::R_TYPE;

	case InstType::FMADD_S:
	case InstType::FMSUB_S:
	case InstType::FNMSUB_S:
	case InstType::FNMADD_S:
	case InstType::FMADD_D:
	case InstType::FMSUB_D:
	case InstType::FNMSUB_D:
	case InstType::FNMADD_D:
		return InstFormat::R4_TYPE;

	case InstType::JALR:
	case InstType::LB:
	case InstType::LH:
	case InstType::LW:
	case InstType::LBU:
	case InstType::LHU:
	case InstType::ADDI:
	case InstType::SLTI:
	case InstType::SLTIU:
	case InstType::XORI:
	case InstType::ORI:
	case InstType::ANDI:
	case InstType::FENCE:
	case InstType::FENCE_I:
	case InstType::ECALL:
	case InstType::EBREAK:
	case InstType::CSRRW:
	case InstType::CSRRS:
	case InstType::CSRRC:
	case InstType::CSRRWI:
	case InstType::CSRRSI:
	case InstType::CSRRCI:
	case InstType::LWU:
	case InstType::LD:
	case InstType::SLLI:
	case InstType::SRLI:
	case InstType::SRAI:
	case InstType::ADDIW:
	case InstType::FLW:
	case InstType::FLD:
		return InstFormat::I_TYPE;

	case InstType::SB:
	case InstType::SH:
	case InstType::SW:
	case InstType::SD:
	case InstType::FSW:
	case InstType::FSD:
		return InstFormat::S_TYPE;

	case InstType::BEQ:
	case InstType::BNE:
	case InstType::BLT:
	case InstType::BGE:
	case InstType::BLTU:
	case InstType::BGEU:
		return InstFormat::B_TYPE;

	case InstType::LUI:
	case InstType::AUIPC:
		return InstFormat::U_TYPE;

	case InstType::JAL:
		return InstFormat::J_TYPE;
	default:
		std::cout << "INVALID instruction format!\n";
		break;
	}
	return InstFormat::INVALID;
}

inline std::string GetInstName(InstType inst_t)
{
	std::string name;
	switch (inst_t) {
	case InstType::INVALID: name = "INVALID"; break;

	// RV32I Base Inst Set
	case InstType::LUI:		name = "LUI"; break;
	case InstType::AUIPC:	name = "AUIPC"; break;
	case InstType::JAL:		name = "JAL"; break;
	case InstType::JALR:	name = "JALR"; break;
	case InstType::BEQ:		name = "BEQ"; break;
	case InstType::BNE:		name = "BNE"; break;
	case InstType::BLT:		name = "BLT"; break;
	case InstType::BGE:		name = "BGE"; break;
	case InstType::BLTU:	name = "BLTU"; break;
	case InstType::BGEU:	name = "BGEU"; break;
	case InstType::LB:		name = "LB"; break;
	case InstType::LH:		name = "LH"; break;
	case InstType::LW:		name = "LW"; break;
	case InstType::LBU:		name = "LBU"; break;
	case InstType::LHU:		name = "LHU"; break;
	case InstType::SB:		name = "SB"; break;
	case InstType::SH:		name = "SH"; break;
	case InstType::SW:		name = "SW"; break;
	case InstType::ADDI:	name = "ADDI"; break;
	case InstType::SLTI:	name = "SLTI"; break;
	case InstType::SLTIU:	name = "SLTIU"; break;
	case InstType::XORI:	name = "XORI"; break;
	case InstType::ORI:		name = "ORI"; break;
	case InstType::ANDI:	name = "ANDI"; break;
	// case InstType::SLLI:	name = "SLLI"; break;
	// case InstType::SRLI:	name = "SRLI"; break;
	// case InstType::SRAI:	name = "SRAI"; break;
	case InstType::ADD:		name = "ADD"; break;
	case InstType::SUB:		name = "SUB"; break;
	case InstType::SLL:		name = "SLL"; break;
	case InstType::SLT:		name = "SLT"; break;
	case InstType::SLTU:	name = "SLTU"; break;
	case InstType::XOR:		name = "XOR"; break;
	case InstType::SRL:		name = "SRL"; break;
	case InstType::SRA:		name = "SRA"; break;
	case InstType::OR:		name = "OR"; break;
	case InstType::AND:		name = "AND"; break;
	case InstType::FENCE:	name = "FENCE"; break;
	case InstType::FENCE_I:	name = "FENCE_I"; break;
	case InstType::ECALL:	name = "ECALL"; break;
	case InstType::EBREAK:	name = "EBREAK"; break;
	case InstType::CSRRW:	name = "CSRRW"; break;
	case InstType::CSRRS:	name = "CSRRS"; break;
	case InstType::CSRRC:	name = "CSRRC"; break;
	case InstType::CSRRWI:	name = "CSRRWI"; break;
	case InstType::CSRRSI:	name = "CSRRSI"; break;
	case InstType::CSRRCI:	name = "CSRRCI"; break;

	// RV64I Base Instruction Set(in addition to RV32I)
	case InstType::LWU: name = "LWU"; break;
	case InstType::LD: name = "LD"; break;
	case InstType::SD: name = "SD"; break;
	case InstType::SLLI: name = "SLLI"; break;
	case InstType::SRLI: name = "SRLI"; break;
	case InstType::SRAI: name = "SRAI"; break;
	case InstType::ADDIW: name = "ADDIW"; break;
	case InstType::SLLIW: name = "SLLIW"; break;
	case InstType::SRLIW: name = "SRLIW"; break;
	case InstType::SRAIW: name = "SRAIW"; break;
	case InstType::ADDW: name = "ADDW"; break;
	case InstType::SUBW: name = "SUBW"; break;
	case InstType::SLLW: name = "SLLW"; break;
	case InstType::SRLW: name = "SRLW"; break;
	case InstType::SRAW: name = "SRAW"; break;

	// RV32M Standard Extension
	case InstType::MUL:		name = "MUL"; break;
	case InstType::MULH:	name = "MULH"; break;
	case InstType::MULHSU:	name = "MULHSU"; break;
	case InstType::MULHU:	name = "MULHU"; break;
	case InstType::DIV:		name = "DIV"; break;
	case InstType::DIVU:	name = "DIVU"; break;
	case InstType::REM:		name = "REM"; break;
	case InstType::REMU:	name = "REMU"; break;

	// RV64M Standard Extension(in addition to RV32M)
	case InstType::MULW:	name = "MULW"; break;
	case InstType::DIVW:	name = "DIVW"; break;
	case InstType::DIVUW:	name = "DIVUW"; break;
	case InstType::REMW:	name = "REMW"; break;
	case InstType::REMUW:	name = "REMUW"; break;

	// RV32A Standard Extension
	case InstType::LR_W:	name = "LR_W"; break;
	case InstType::SC_W:	name = "SC_W"; break;
	case InstType::AMOSWAP_W: name = "AMOSWAP_W"; break;
	case InstType::AMOADD_W: name = "AMOADD_W"; break;
	case InstType::AMOXOR_W: name = "AMOXOR_W"; break;
	case InstType::AMOAND_W: name = "AMOAND_W"; break;
	case InstType::AMOOR_W: name = "AMOOR_W"; break;
	case InstType::AMOMIN_W: name = "AMOMIN_W"; break;
	case InstType::AMOMAX_W: name = "AMOMAX_W"; break;
	case InstType::AMOMINU_W: name = "AMOMINU_W"; break;
	case InstType::AMOMAXU_W: name = "AMOMAXU_W"; break;

	// RV64A Standard Extension(in addition to RV32A)
	case InstType::LR_D: name = "LR_D"; break;
	case InstType::SC_D: name = "SC_D"; break;
	case InstType::AMOSWAP_D: name = "AMOSWAP_D"; break;
	case InstType::AMOADD_D: name = "AMOADD_D"; break;
	case InstType::AMOXOR_D: name = "AMOXOR_D"; break;
	case InstType::AMOAND_D: name = "AMOAND_D"; break;
	case InstType::AMOOR_D: name = "AMOOR_D"; break;
	case InstType::AMOMIN_D: name = "AMOMIN_D"; break;
	case InstType::AMOMAX_D: name = "AMOMAX_D"; break;
	case InstType::AMOMINU_D: name = "AMOMINU_D"; break;
	case InstType::AMOMAXU_D: name = "AMOMAXU_D"; break;

	// RV32F Standard Extension
	case InstType::FLW: name = "FLW"; break;
	case InstType::FSW: name = "FSW"; break;
	case InstType::FMADD_S: name = "FMADD_S"; break;
	case InstType::FMSUB_S: name = "FMSUB_S"; break;
	case InstType::FNMSUB_S: name = "FNMSUB_S"; break;
	case InstType::FNMADD_S: name = "FNMADD_S"; break;
	case InstType::FADD_S: name = "FADD_S"; break;
	case InstType::FSUB_S: name = "FSUB_S"; break;
	case InstType::FMUL_S: name = "FMUL_S"; break;
	case InstType::FDIV_S: name = "FDIV_S"; break;
	case InstType::FSQRT_S: name = "FSQRT_S"; break;
	case InstType::FSGNJ_S: name = "FSGNJ_S"; break;
	case InstType::FSGNJN_S: name = "FSGNJN_S"; break;
	case InstType::FSGNJX_S: name = "FSGNJX_S"; break;
	case InstType::FMIN_S: name = "FMIN_S"; break;
	case InstType::FMAX_S: name = "FMAX_S"; break;
	case InstType::FCVT_W_S: name = "FCVT_W_S"; break;
	case InstType::FCVT_WU_S: name = "FCVT_WU_S"; break;
	case InstType::FMV_X_W: name = "FMV_X_W"; break;
	case InstType::FEQ_S: name = "FEQ_S"; break;
	case InstType::FLT_S: name = "FLT_S"; break;
	case InstType::FLE_S: name = "FLE_S"; break;
	case InstType::FCLASS_S: name = "FCLASS_S"; break;
	case InstType::FCVT_S_W: name = "FCVT_S_W"; break;
	case InstType::FCVT_S_WU: name = "FCVT_S_WU"; break;
	case InstType::FMV_W_X: name = "FMV_W_X"; break;

	// RV64F Standard Extension(in addition to RV32F)
	case InstType::FCVT_L_S: name = "FCVT_L_S"; break;
	case InstType::FCVT_LU_S: name = "FCVT_LU_S"; break;
	case InstType::FCVT_S_L: name = "FCVT_S_L"; break;
	case InstType::FCVT_S_LU: name = "FCVT_S_LU"; break;

	// RV32D Standard Extension
	case InstType::FLD: name = "FLD"; break;
	case InstType::FSD: name = "FSD"; break;
	case InstType::FMADD_D: name = "FMADD_D"; break;
	case InstType::FMSUB_D: name = "FMSUB_D"; break;
	case InstType::FNMSUB_D: name = "FNMSUB_D"; break;
	case InstType::FNMADD_D: name = "FNMADD_D"; break;
	case InstType::FADD_D: name = "FADD_D"; break;
	case InstType::FSUB_D: name = "FSUB_D"; break;
	case InstType::FMUL_D: name = "FMUL_D"; break;
	case InstType::FDIV_D: name = "FDIV_D"; break;
	case InstType::FSQRT_D: name = "FSQRT_D"; break;
	case InstType::FSGNJ_D: name = "FSGNJ_D"; break;
	case InstType::FSGNJN_D: name = "FSGNJN_D"; break;
	case InstType::FSGNJX_D: name = "FSGNJX_D"; break;
	case InstType::FMIN_D: name = "FMIN_D"; break;
	case InstType::FMAX_D: name = "FMAX_D"; break;
	case InstType::FCVT_S_D: name = "FCVT_S_D"; break;
	case InstType::FCVT_D_S: name = "FCVT_D_S"; break;
	case InstType::FEQ_D: name = "FEQ_D"; break;
	case InstType::FLT_D: name = "FLT_D"; break;
	case InstType::FLE_D: name = "FLE_D"; break;
	case InstType::FCLASS_D: name = "FCLASS_D"; break;
	case InstType::FCVT_W_D: name = "FCVT_W_D"; break;
	case InstType::FCVT_WU_D: name = "FCVT_WU_D"; break;
	case InstType::FCVT_D_W: name = "FCVT_D_W"; break;
	case InstType::FCVT_D_WU: name = "FCVT_D_WU"; break;

	// RV64D Standard Extension(in addition to RV32D)
	case InstType::FCVT_L_D: name = "FCVT_L_D"; break;
	case InstType::FCVT_LU_D: name = "FCVT_LU_D"; break;
	case InstType::FMV_X_D:	name = "FMV_X_D"; break;
	case InstType::FCVT_D_L: name = "FCVT_D_L"; break;
	case InstType::FCVT_D_LU: name = "FCVT_D_LU"; break;
	case InstType::FMV_D_X:	name = "FMV_D_X"; break;
	}
	return name;
}

constexpr CSRType GetCSRType(uint32_t imm_i_11_0) {
	switch (imm_i_11_0) {
	case 0x001: return CSRType::fflags;
	case 0x002: return CSRType::frm;
	case 0x003: return CSRType::fcsr;
	case 0xc00: return CSRType::cycle;
	case 0xc01: return CSRType::time;
	case 0xc02: return CSRType::instret;
	case 0xc80: return CSRType::cycleh;
	case 0xc81: return CSRType::timeh;
	case 0xc82: return CSRType::instreth;
	}
	return CSRType::INVALID;
}

class Instruction {
public:
	Instruction(uint32_t inst) {
		m_bit = inst;
		m_type = GetInstType(inst);
		m_format = GetInstFormat(m_type);
		m_imm = -1;
		m_rd = m_rs1 = m_rs2 = m_rs3 = m_aq = m_rl = -1;

		switch (m_format) {
		case InstFormat::R_TYPE: {
			m_rd = (int8_t)((m_bit >> BIT_OFFSET_REGISTER_DEST) & BIT_ALIGN_MASK_REGISTER_DEST);
			m_rs1 = (int8_t)((m_bit >> BIT_OFFSET_REGISTER_SRC1) & BIT_ALIGN_MASK_REGISTER_SRC1);
			m_rs2 = (int8_t)((m_bit >> BIT_OFFSET_REGISTER_SRC2) & BIT_ALIGN_MASK_REGISTER_SRC2);
			switch (m_type) {
			case InstType::LR_W:
			case InstType::SC_W:
			case InstType::AMOSWAP_W:
			case InstType::AMOADD_W:
			case InstType::AMOXOR_W:
			case InstType::AMOAND_W:
			case InstType::AMOOR_W:
			case InstType::AMOMIN_W:
			case InstType::AMOMAX_W:
			case InstType::AMOMINU_W:
			case InstType::AMOMAXU_W:
			case InstType::LR_D:
			case InstType::SC_D:
			case InstType::AMOSWAP_D:
			case InstType::AMOADD_D:
			case InstType::AMOXOR_D:
			case InstType::AMOAND_D:
			case InstType::AMOOR_D:
			case InstType::AMOMIN_D:
			case InstType::AMOMAX_D:
			case InstType::AMOMINU_D:
			case InstType::AMOMAXU_D:
				uint32_t funct7 = (m_bit >> BIT_OFFSET_FUNCT7) & BIT_ALIGN_MASK_FUNCT7;
				m_aq = (int8_t)((funct7 >> 1) & 0b00000001);
				m_rl = (int8_t)(funct7 & 0b00000001);
				break;
			}
			break;
		}
		case InstFormat::R4_TYPE: {
			m_rd = (int8_t)((m_bit >> BIT_OFFSET_REGISTER_DEST) & BIT_ALIGN_MASK_REGISTER_DEST);
			m_rs1 = (int8_t)((m_bit >> BIT_OFFSET_REGISTER_SRC1) & BIT_ALIGN_MASK_REGISTER_SRC1);
			m_rs2 = (int8_t)((m_bit >> BIT_OFFSET_REGISTER_SRC2) & BIT_ALIGN_MASK_REGISTER_SRC2);
			m_rs3 = (int8_t)((m_bit >> BIT_OFFSET_REGISTER_SRC3) & BIT_ALIGN_MASK_REGISTER_SRC3);
			break;
		}
		case InstFormat::I_TYPE: {
			m_rd = (int8_t)((m_bit >> BIT_OFFSET_REGISTER_DEST) & BIT_ALIGN_MASK_REGISTER_DEST);
			m_rs1 = (int8_t)((m_bit >> BIT_OFFSET_REGISTER_SRC1) & BIT_ALIGN_MASK_REGISTER_SRC1);

			int64_t temp = (int64_t)((m_bit >> BIT_OFFSET_IMM_I_11_0) & BIT_ALIGN_MASK_IMM_I_11_0);
			if (0 < (temp & BIT_ALIGN_MASK_IMM_I_11_0_SIGN)) {
				temp = temp | ~(int64_t)BIT_ALIGN_MASK_IMM_I_11_0;
			}
			m_imm = temp;
			break;
		}
		case InstFormat::S_TYPE: {
			m_rs1 = (int8_t)((m_bit >> BIT_OFFSET_REGISTER_SRC1) & BIT_ALIGN_MASK_REGISTER_SRC1);
			m_rs2 = (int8_t)((m_bit >> BIT_OFFSET_REGISTER_SRC2) & BIT_ALIGN_MASK_REGISTER_SRC2);

			uint32_t imm11_5 = (m_bit >> BIT_OFFSET_IMM_S_11_5) & BIT_ALIGN_MASK_IMM_S_11_5;
			uint32_t imm4_0 = (m_bit >> BIT_OFFSET_IMM_S_4_0) & BIT_ALIGN_MASK_IMM_S_4_0;
			m_imm = (int64_t)(imm4_0 | ((imm11_5 << 5) & 0b00001111'11100000));
			break;
		}
		case InstFormat::B_TYPE: {
			m_rs1 = (int8_t)((m_bit >> BIT_OFFSET_REGISTER_SRC1) & BIT_ALIGN_MASK_REGISTER_SRC1);
			m_rs2 = (int8_t)((m_bit >> BIT_OFFSET_REGISTER_SRC2) & BIT_ALIGN_MASK_REGISTER_SRC2);

			uint32_t imm12 = (m_bit >> BIT_OFFSET_IMM_B_12) & BIT_ALIGN_MASK_IMM_B_12;
			uint32_t imm11 = (m_bit >> BIT_OFFSET_IMM_B_11) & BIT_ALIGN_MASK_IMM_B_11;
			uint32_t imm10_5 = (m_bit >> BIT_OFFSET_IMM_B_10_5) & BIT_ALIGN_MASK_IMM_B_10_5;
			uint32_t imm4_1 = (m_bit >> BIT_OFFSET_IMM_B_4_1) & BIT_ALIGN_MASK_IMM_B_4_1;
			m_imm = (int64_t)(((imm12 << 12)	& 0b00010000'00000000)
							| ((imm11 << 11)	& 0b00001000'00000000)
							| ((imm10_5 << 5)	& 0b00000111'11100000)
							| ((imm4_1 << 1)	& 0b00000000'00011110));
			break;
		}
		case InstFormat::U_TYPE: {
			m_rd = (int8_t)((m_bit >> BIT_OFFSET_REGISTER_DEST) & BIT_ALIGN_MASK_REGISTER_DEST);
			m_imm = (int64_t)(m_bit & MASK_IMM_U_31_12);
			break;
		}
		case InstFormat::J_TYPE: {
			m_rd = (int8_t)((m_bit >> BIT_OFFSET_REGISTER_DEST) & BIT_ALIGN_MASK_REGISTER_DEST);
			
			uint32_t imm20 = (m_bit >> BIT_OFFSET_IMM_J_20) & BIT_ALIGN_MASK_IMM_J_20;
			uint32_t imm19_12 = (m_bit >> BIT_OFFSET_IMM_J_19_12) & BIT_ALIGN_MASK_IMM_J_19_12;
			uint32_t imm11 = (m_bit >> BIT_OFFSET_IMM_J_11) & BIT_ALIGN_MASK_IMM_J_11;
			uint32_t imm10_1 = (m_bit >> BIT_OFFSET_IMM_J_10_1) & BIT_ALIGN_MASK_IMM_J_10_1;
			int64_t temp = (int64_t)(((imm20 << 20)		& 0b00000000'00010000'00000000'00000000)
									| ((imm19_12 << 12)	& 0b00000000'00001111'11110000'00000000)
									| ((imm11 << 11)	& 0b00000000'00000000'00001000'00000000)
									| ((imm10_1 << 1)	& 0b00000000'00000000'00000111'11111110));
			if (1 == imm20) {
				temp = temp | ~(int64_t)0b00000000'00011111'11111111'11111111;
			}

			m_imm = temp;
			break;
		}
		default:
			std::cout << "INVALID instruction!\n";
			while (true);
			break;
		}
	}

	uint32_t		m_bit;
	InstType		m_type;
	InstFormat		m_format;
	int8_t			m_rd;
	int8_t			m_rs1;
	int8_t			m_rs2;
	int8_t			m_rs3;
	int8_t			m_aq;
	int8_t			m_rl;
	int64_t			m_imm;
};

std::ostream& operator<<(std::ostream& os, const Instruction& inst) {
	os << "[Bit]: " << std::bitset<32>(inst.m_bit) << ", [Instruction]: ";
	os.flags(std::ios::left);
	os.width(9);
	os << GetInstName(inst.m_type);
	os.flags(std::ios::right);
	switch (inst.m_format) {
	case InstFormat::R_TYPE:
		os.fill(' ');
		os.width(2); os << "x";
		os.width(2); os << std::to_string(inst.m_rd);
		os.width(3); os << "x";
		os.width(2); os << std::to_string(inst.m_rs1);
		os.width(3); os << "x";
		os.width(2); os << std::to_string(inst.m_rs2);
		os.width(1); 
		break;
	case InstFormat::R4_TYPE:
		os.fill(' ');
		os.width(2); os << "x";
		os.width(2); os << std::to_string(inst.m_rd);
		os.width(3); os << "x";
		os.width(2); os << std::to_string(inst.m_rs1);
		os.width(3); os << "x";
		os.width(2); os << std::to_string(inst.m_rs2);
		os.width(3); os << "x";
		os.width(2); os << std::to_string(inst.m_rs3);
		os.width(1); 
		break;
	case InstFormat::I_TYPE:
		os.fill(' ');
		os.width(2); os << "x";
		os.width(2); os << std::to_string(inst.m_rd);
		os.width(3); os << "x";
		os.width(2); os << std::to_string(inst.m_rs1);
		os.width(2); os << " " << std::to_string(inst.m_imm);
		os.width(1); 
		break;
	case InstFormat::S_TYPE:
		os.fill(' ');
		os.width(2); os << "x";
		os.width(2); os << std::to_string(inst.m_rs1);
		os.width(3); os << "x";
		os.width(2); os << std::to_string(inst.m_rs2);
		os.width(2); os << " " << std::to_string(inst.m_imm);
		os.width(1);
		break;
	case InstFormat::B_TYPE:
		os.fill(' ');
		os.width(2); os << "x";
		os.width(2); os << std::to_string(inst.m_rs1);
		os.width(3); os << "x";
		os.width(2); os << std::to_string(inst.m_rs2);
		os.width(2); os << " " << std::to_string(inst.m_imm);
		os.width(1);
		break;
	case InstFormat::U_TYPE:
		os.fill(' ');
		os.width(2); os << "x";
		os.width(2); os << std::to_string(inst.m_rd);
		os.width(2); os << "  0x" << std::hex << inst.m_imm;
		os.width(1);
		break;
	case InstFormat::J_TYPE:
		os.fill(' ');
		os.width(2); os << "x";
		os.width(2); os << std::to_string(inst.m_rd);
		os.width(2); os << " " << inst.m_imm;
		os.width(1);
		break;
	}
	os.width(5);
	os << "";
	return os;
}
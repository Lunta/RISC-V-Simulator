#pragma once

/*
|-----------|-----------|---------------------------------------|--------|
| Register	| ABI Name	| Description							| Saver	 |
|-----------|-----------|---------------------------------------|--------|
| x0		| zero		| Hard-wired zero						| —		 |
| x1		| ra		| Return address						| Caller |
| x2		| sp		| Stack pointer							| Callee |
| x3		| gp		| Global pointer						| —		 |
| x4		| tp		| Thread pointer						| —		 |
| x5		| t0		| Temporary/alternate link register		| Caller |
| x6–7		| t1–2		| Temporaries							| Caller |
| x8		| s0/fp		| Saved register/frame pointer			| Callee |
| x9		| s1		| Saved register						| Callee |
| x10–11	| a0–1		| Function arguments/return values		| Caller |
| x12–17	| a2–7		| Function arguments					| Caller |
| x18–27	| s2–11		| Saved registers						| Callee |
| x28–31	| t3–6		| Temporaries							| Caller |
|-----------|-----------|---------------------------------------|--------|
| f0–7		| ft0–7		| FP temporaries						| Caller |
| f8–9		| fs0–1		| FP saved registers					| Callee |
| f10–11	| fa0–1		| FP arguments/return values			| Caller |
| f12–17	| fa2–7		| FP arguments							| Caller |
| f18–27	| fs2–11	| FP saved registers					| Callee |
| f28–31	| ft8–11	| FP temporaries						| Caller |
|-----------|-----------|---------------------------------------|--------|
*/

class Register {
public:
	Register() {
		memset(x, 0, sizeof(int32_t) * 32);
		memset(f, 0, sizeof(float) * 32);
	}
	std::string GetABIName(uint8_t reg_idx, InstType inst_type) {
		switch (inst_type) {
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
		case InstType::FMADD_S:
		case InstType::FMSUB_S:
		case InstType::FNMSUB_S:
		case InstType::FNMADD_S:
		case InstType::FMADD_D:
		case InstType::FMSUB_D:
		case InstType::FNMSUB_D:
		case InstType::FNMADD_D:
		case InstType::FLW:
		case InstType::FLD:
		case InstType::FSW:
		case InstType::FSD:
			if (8 > reg_idx)		return "ft" + std::to_string(reg_idx);
			else if (10 > reg_idx)	return "fs" + std::to_string(reg_idx - 8);
			else if (12 > reg_idx)  return "fa" + std::to_string(reg_idx - 10);
			else if (18 > reg_idx)  return "fa" + std::to_string(reg_idx - 10);
			else if (28 > reg_idx)	return "fs" + std::to_string(reg_idx - 16);
			else					return "ft" + std::to_string(reg_idx - 20);
		default:
			if (0 == reg_idx)		return std::string("zero");
			else if (1 == reg_idx)	return std::string("ra");
			else if (2 == reg_idx)	return std::string("sp");
			else if (3 == reg_idx)	return std::string("gp");
			else if (4 == reg_idx)	return std::string("tp");
			else if (5 == reg_idx)	return std::string("t0");
			else if (8 > reg_idx)	return "t" + std::to_string(reg_idx - 5);
			else if (8 == reg_idx)	return std::string("s0/fp");
			else if (9 == reg_idx)	return std::string("s1");
			else if (12 > reg_idx)  return "a" + std::to_string(reg_idx - 10);
			else if (18 > reg_idx)  return "a" + std::to_string(reg_idx - 10);
			else if (28 > reg_idx)	return "s" + std::to_string(reg_idx - 16);
			else					return "t" + std::to_string(reg_idx - 25);
		}
	}

public:
	uint32_t	x[32];
	float		f[32];
};
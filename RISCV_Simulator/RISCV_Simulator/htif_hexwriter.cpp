// See LICENSE for license details.

#include <iostream>
#include <assert.h>
#include "htif_hexwriter.h"
#include <bitset>
#include "instruction.h"

htif_hexwriter_t::htif_hexwriter_t(size_t b, size_t w, size_t d)
  : base(b), width(w), depth(d)
{
}

void htif_hexwriter_t::read_chunk(addr_t taddr, size_t len, void* vdst)
{
	taddr -= base;

	assert(len % chunk_align() == 0);
	assert(taddr < width*depth);
	assert(taddr + len <= width * depth);

	uint8_t* dst = (uint8_t*)vdst;
	while (len)
	{
		if (mem[taddr / width].size() == 0)
			mem[taddr / width].resize(width, 0);

		for (size_t j = 0; j < width; j++)
			dst[j] = mem[taddr / width][j];

		len -= width;
		taddr += width;
		dst += width;
	}
}

void htif_hexwriter_t::write_chunk(addr_t taddr, size_t len, const void* vsrc)
{
	taddr -= base;

	assert(len % chunk_align() == 0);
	assert(taddr < width*depth);
	assert(taddr + len <= width * depth);

	const uint8_t* src = (const uint8_t*)vsrc;
	addr_t addr = taddr / width;

	icache[addr] = *((const uint32_t*)src);
	//if (0 != icache[addr]) {
	//	std::cout << "[depth]: " << addr << ", [instruction bit field]: " << std::bitset<32>(icache[addr]);
	//	std::cout << " , [name]: " << GetInstName(GetInstType(icache[addr])) << std::endl;
	//}
	//else {
	//	//while (true);
	//}

	//uint8_t* inst_field = (uint8_t*)(&icache[addr]);
	//int inst_field_idx = 0;
	//for (int i = width - 1; i >= 0; --i)
	//	inst_field[inst_field_idx++] = src[i];

	while (len) {
		if (mem[addr].size() == 0)
			mem[addr].resize(width, 0);

		for (size_t j = 0; j < width; j++)
			mem[addr][j] = src[j];

		len -= width;
		taddr += width;
	}
}

std::ostream& operator<< (std::ostream& o, const htif_hexwriter_t& h)
{
	//std::ios_base::fmtflags flags = o.setf(std::ios::hex, std::ios::basefield);
	//for (size_t addr = 0; addr < h.depth; addr++) {
	//	std::map<addr_t, std::vector<char> >::const_iterator i = h.mem.find(addr);
	//	if (i == h.mem.end())
	//		for (size_t j = 0; j < h.width; j++)
	//			o << "00";
	//	else
	//		for (size_t j = 0; j < h.width; j++)
	//			o << ((i->second[h.width - j - 1] >> 4) & 0xF) << (i->second[h.width - j - 1] & 0xF);
	//	o << std::endl;
	//}
	//o.setf(flags);

	for (size_t addr = 0; addr < h.depth; addr++) {
		std::map<addr_t, uint32_t>::const_iterator i = h.icache.find(addr);
		if (i != h.icache.end()) {
			if (0 == i->second) continue;
			o << "[depth]: " << addr << ", [instruction bit field]: " << std::bitset<32>(i->second);
			o << " , [name]: " << GetInstName(GetInstType(i->second)) << std::endl;
		}
	}

	return o;
}

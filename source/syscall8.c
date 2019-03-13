/* syscall8.c

Copyright (c) 2010 Hermes <www.elotrolado.net>
All rights reserved.

Redistribution and use in source and binary forms, with or without modification, are 
permitted provided that the following conditions are met:

- Redistributions of source code must retain the above copyright notice, this list of 
  conditions and the following disclaimer. 
- Redistributions in binary form must reproduce the above copyright notice, this list 
  of conditions and the following disclaimer in the documentation and/or other 
  materials provided with the distribution. 
- The names of the contributors may not be used to endorse or promote products derived 
  from this software without specific prior written permission. 

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY 
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF 
MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL 
THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, 
PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS 
INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, 
STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF 
THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*/

#include "syscall8.h"

extern float c_firmware;
extern uint8_t bdisk_mode;

static uint64_t syscall8(register uint64_t cmd, register uint64_t param1, register  uint64_t param2, register  uint64_t param3)
{
	__asm__  volatile ("li      11, 0x8\n\t"
					   "sc\n\t" : "=r" (cmd), "=r" (param1), "=r" (param2), "=r" (param3)
					   : "r" (cmd), "r" (param1), "r" (param2), "r" (param3)
					   : "%r0", "%r12", "%lr", "%ctr", "%xer", "%cr0", "%cr1", "%cr5", "%cr6", "%cr7", "memory");
	return cmd;
}

static uint64_t syscall10(register uint64_t cmd, register uint64_t param1, register  uint64_t param2, register  uint64_t param3)
{
	__asm__  volatile ("li      11, 0xa\n\t"
					   "sc\n\t" : "=r" (cmd), "=r" (param1), "=r" (param2), "=r" (param3)
					   : "r" (cmd), "r" (param1), "r" (param2), "r" (param3)
					   : "%r0", "%r12", "%lr", "%ctr", "%xer", "%cr0", "%cr1", "%cr5", "%cr6", "%cr7", "memory");
	return cmd;
}

int sys8_disable(uint64_t key)
{

	return (int) syscall8(0ULL, key, 0ULL, 0ULL);
}

int sys8_enable(uint64_t key)
{
	if(c_firmware==4.21f && !bdisk_mode)
		return (int) syscall10(1ULL, key, 0ULL, 0ULL);
	else
		return (int) syscall8(1ULL, key, 0ULL, 0ULL);
}

uint64_t sys8_memcpy(uint64_t dst, uint64_t src, uint64_t size)
{
	if(c_firmware==4.21f && !bdisk_mode)
		return syscall10(2ULL, dst, src, size);
	else
		return syscall8(2ULL, dst, src, size);

}

uint64_t sys8_memset(uint64_t dst, uint64_t val, uint64_t size)
{

	return syscall8(3ULL, dst, val, size);

}

uint64_t sys8_call(uint64_t addr, uint64_t param1, uint64_t param2)
{

	return syscall8(4ULL, addr, param1, param2);

}

uint64_t sys8_alloc(uint64_t size, uint64_t pool)
{

	return syscall8(5ULL, size, pool, 0ULL);

}

uint64_t sys8_free(uint64_t addr, uint64_t pool)
{

	return syscall8(6ULL, addr, pool, 0ULL);

}

void sys8_panic(void)
{

	syscall8(7ULL, 0ULL, 0ULL, 0ULL);

}

int sys8_perm_mode(uint64_t mode)
{

	return (int) syscall8(8ULL, mode, 0ULL, 0ULL);
}

uint64_t sys8_path_table(uint64_t addr_table)
{
	if(c_firmware==4.21f && !bdisk_mode)
		return syscall10(9ULL, addr_table, 0ULL, 0ULL);
	else
		return syscall8(9ULL, addr_table, 0ULL, 0ULL);
}

#ifndef __ARMV7_H__
#define __ARMV7_H__
/* 
 * Copyright (c) 2011-2021, Shanghai Real-Thread Electronic Technology Co.,Ltd 
 * 
 * This software is dual-licensed: you can redistribute it and/or modify 
 * it under the terms of the GNU General Public License version 2 as 
 * published by the Free Software Foundation. For the terms of this 
 * license, see <http://www.gnu.org/licenses/>. 
 * 
 * You are free to use this software under the terms of the GNU General 
 * Public License, but WITHOUT ANY WARRANTY; without even the implied 
 * warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
 * See the GNU General Public License for more details. 
 * 
 * Alternatively for commercial application, you can contact us 
 * by email <business@rt-thread.com> for commercial license. 
 */

/* the exception stack without VFP registers */
struct rt_hw_exp_stack
{
	unsigned long r0;
	unsigned long r1;
	unsigned long r2;
	unsigned long r3;
	unsigned long r4;
	unsigned long r5;
	unsigned long r6;
	unsigned long r7;
	unsigned long r8;
	unsigned long r9;
	unsigned long r10;
	unsigned long fp;
	unsigned long ip;
	unsigned long sp;
	unsigned long lr;
	unsigned long pc;
	unsigned long cpsr;
};

#define USERMODE    0x10
#define FIQMODE     0x11
#define IRQMODE     0x12
#define SVCMODE     0x13
#define MONITORMODE 0x16
#define ABORTMODE   0x17
#define HYPMODE     0x1b
#define UNDEFMODE   0x1b
#define MODEMASK    0x1f
#define NOINT       0xc0

#define T_Bit       (1<<5)
#define F_Bit       (1<<6)
#define I_Bit       (1<<7)
#define A_Bit       (1<<8)
#define E_Bit       (1<<9)
#define J_Bit       (1<<24)

void rt_hw_mmu_init(void);

#endif

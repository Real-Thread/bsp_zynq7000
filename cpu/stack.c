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
 * 
 *
 * Change Logs:
 * Date           Author       Notes
 * 2011-09-23     Bernard      the first version
 * 2011-10-05     Bernard      add thumb mode
 * 2013-07-15     Bernard      add Cortex-A8 support.
 */
#include <rtthread.h>
#include "zynq7000.h"

/**
 * This function will initialize thread stack
 *
 * @param tentry the entry of thread
 * @param parameter the parameter of entry
 * @param stack_addr the beginning stack address
 * @param texit the function will be called when thread exit
 *
 * @return stack address
 */
rt_uint8_t *rt_hw_stack_init(void *tentry, void *parameter,
                             rt_uint8_t *stack_addr, void *texit)
{
    rt_uint32_t *stk;

    stack_addr += sizeof(rt_uint32_t);
    stack_addr  = (rt_uint8_t *)RT_ALIGN_DOWN((rt_uint32_t)stack_addr, 8);
    stk      = (rt_uint32_t *)stack_addr;
    *(--stk) = (rt_uint32_t)tentry;         /* entry point */
    *(--stk) = (rt_uint32_t)texit;          /* lr */
    *(--stk) = 0xdeadbeef;                  /* r12 */
    *(--stk) = 0xdeadbeef;                  /* r11 */
    *(--stk) = 0xdeadbeef;                  /* r10 */
    *(--stk) = 0xdeadbeef;                  /* r9 */
    *(--stk) = 0xdeadbeef;                  /* r8 */
    *(--stk) = 0xdeadbeef;                  /* r7 */
    *(--stk) = 0xdeadbeef;                  /* r6 */
    *(--stk) = 0xdeadbeef;                  /* r5 */
    *(--stk) = 0xdeadbeef;                  /* r4 */
    *(--stk) = 0xdeadbeef;                  /* r3 */
    *(--stk) = 0xdeadbeef;                  /* r2 */
    *(--stk) = 0xdeadbeef;                  /* r1 */
    *(--stk) = (rt_uint32_t)parameter;      /* r0 : argument */

    /* cpsr */
    if ((rt_uint32_t)tentry & 0x01)
        *(--stk) = SVCMODE | 0x20;          /* thumb mode */
    else
        *(--stk) = SVCMODE;                 /* arm mode   */

    /* return task's current stack address */
    return (rt_uint8_t *)stk;
}


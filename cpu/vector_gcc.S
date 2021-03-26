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
 * 2013-07-05     Bernard      the first version
 */

.section .vectors, "ax"
.code 32

.globl system_vectors
system_vectors:
    ldr pc, _vector_reset
    ldr pc, _vector_undef
    ldr pc, _vector_swi
    ldr pc, _vector_pabt
    ldr pc, _vector_dabt
    ldr pc, _vector_resv
    ldr pc, _vector_irq
    ldr pc, _vector_fiq

.globl _reset
.globl vector_undef
.globl vector_swi
.globl vector_pabt
.globl vector_dabt
.globl vector_resv
.globl vector_irq
.globl vector_fiq

_vector_reset:
    .word _reset
_vector_undef:
    .word vector_undef
_vector_swi:
    .word vector_swi
_vector_pabt:
    .word vector_pabt
_vector_dabt:
    .word vector_dabt
_vector_resv:
    .word vector_resv
_vector_irq:
    .word vector_irq
_vector_fiq:
    .word vector_fiq

.balignl 	16,0xdeadbeef

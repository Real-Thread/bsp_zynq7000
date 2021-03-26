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
 * Change Logs:
 * Date           Author       Notes
 * 2013-07-20     Bernard      first version
 */

#ifndef __GIC_H__
#define __GIC_H__

int arm_gic_dist_init(rt_uint32_t index, rt_uint32_t dist_base, int irq_start);
int arm_gic_cpu_init(rt_uint32_t index, rt_uint32_t cpu_base);

void arm_gic_mask(rt_uint32_t index, int irq);
void arm_gic_umask(rt_uint32_t index, int irq);
void arm_gic_set_cpu(rt_uint32_t index, int irq, unsigned int cpumask);
void arm_gic_set_group(rt_uint32_t index, int vector, int group);

int arm_gic_get_active_irq(rt_uint32_t index);
void arm_gic_ack(rt_uint32_t index, int irq);

void arm_gic_trigger(rt_uint32_t index, int target_cpu, int irq);
void arm_gic_clear_sgi(rt_uint32_t index, int target_cpu, int irq);

void arm_gic_dump_type(rt_uint32_t index);

#endif


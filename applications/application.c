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
 */

#include <rtthread.h>

#include <cp15.h>

/* thread phase init */
static void rt_init_thread_entry(void *parameter)
{
    /* do component initialization */
    rt_components_init();
    rt_kprintf("running on cpu %d\n",
               rt_cpu_get_smp_id() & 0x0f);

    /* add your initialization here */
}

int rt_application_init()
{
    rt_thread_t tid;

    tid = rt_thread_create("init", rt_init_thread_entry, RT_NULL, 2048,
                            RT_THREAD_PRIORITY_MAX/3, 20);
    if (tid != RT_NULL)
        rt_thread_startup(tid);

    return 0;
}


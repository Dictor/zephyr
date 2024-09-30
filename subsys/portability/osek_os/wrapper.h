/*
 * Copyright (c) 2024 Jeonghyun Kim <kimdictor@gmail.com>
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef __OSEK_WRAPPER_H__
#define __OSEK_WRAPPER_H__

#include <zephyr/kernel.h>
#include <osek_os.h>

#include <stdbool.h>

bool osek_task_occupied_resource(TaskRefType task);
void osek_task_list_append(TaskRefType task);
bool osek_task_list_exist(TaskRefType task);
bool osek_is_task_activated(TaskRefType task);
TaskRefType osek_zephyr_thread_to_osek(k_tid_t thread);
void osek_resource_list_append(ResourceType *resource);

#endif
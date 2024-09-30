/*
 * Copyright (c) 2024 Jeonghyun Kim <kimdictor@gmail.com>
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/kernel.h>
#include <zephyr/kernel_structs.h>
#include <osek_os.h>

#include "wrapper.h"

const TaskStateType RUNNING = 0;
const TaskStateType WAITING = 1;
const TaskStateType READY = 2;
const TaskStateType SUSPENDED = 3;
const TaskType INVALID_TASK = {NULL};
const ResourceType RES_SCHEDULER;
const TickType OSMAXALLOWEDVALUE;
const TickType OSTICKSPERBASE;
const TickType OSMINCYCLE;
const AppModeType OSDEFAULTAPPMODE;

// every OSEK task is expected to exist in this list before os started
static sys_slist_t osek_task_list = SYS_SLIST_STATIC_INIT(&osek_task_list);

// every OSEK resource is expected to exist in this list before os started
static sys_slist_t osek_resource_list = SYS_SLIST_STATIC_INIT(&osek_resource_list);

bool osek_task_occupied_resource(TaskRefType task)
{
	ResourceType *resource, *tmp;

	SYS_SLIST_FOR_EACH_CONTAINER_SAFE(&osek_resource_list, resource, tmp, node) {
		if (resource->occupier == task->id) {
			return true;
		}
	}
	return false;
}

void osek_task_list_append(TaskRefType task)
{
	sys_slist_append(&osek_task_list, &task->node);
}

bool osek_task_list_exist(TaskRefType task)
{
	return sys_slist_find(&osek_task_list, &task->node, NULL);
}

bool osek_is_task_activated(TaskRefType task)
{
	uint8_t state = task->id->base.thread_state;
	const uint8_t inactivate = _THREAD_ABORTING | _THREAD_DEAD | _THREAD_SUSPENDED |
				   _THREAD_SUSPENDING | _THREAD_PRESTART;
	return (state & inactivate) > 0 ? false : true;
}

TaskRefType osek_zephyr_thread_to_osek(k_tid_t thread)
{
	TaskRefType task, tmp;

	SYS_SLIST_FOR_EACH_CONTAINER_SAFE(&osek_task_list, task, tmp, node) {
		if (task->id == thread) {
			return task;
		}
	}
	return NULL;
}

void osek_resource_list_append(ResourceType *resource)
{
	sys_slist_append(&osek_resource_list, &resource->node);
}
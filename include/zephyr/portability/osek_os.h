/*
 * Copyright (c) 2024 Jeonghyun Kim <kimdictor@gmail.com>
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef ZEPHYR_INCLUDE_OSEK_OS_H_
#define ZEPHYR_INCLUDE_OSEK_OS_H_

// TaskType identifies a task. (ch 13.2.1)
typedef struct {
} TaskType;

// TaskRefType points to a variable of TaskType. (ch 13.2.1)
typedef TaskType *TaskRefType;

// TaskStateType identifies the state of a task. (ch 13.2.1)
typedef unsigned char TaskStateType;

// TaskStateRefType points to a variable of the data type TaskStateType. (ch 13.2.1)
typedef TaskStateType *TaskStateRefType;

// ResourceType is data type for a resource.(ch 13.4.1)
typedef struct {
} ResourceType;

// EventMaskType is data type of the event mask. (ch 13.5.1)
typedef struct {
} EventMaskType;

// EventMaskRefType is reference to an event mask. (ch 13.5.1)
typedef EventMaskType *EventMaskRefType;

// TickType represents count values in ticks. (ch 13.6.1)
typedef struct {
} TickType;

// TickRefType points to the data type TickType. (ch 13.6.1)
typedef TickType *TickRefType;

// AlarmBaseType represents a structure for storage of counter characteristics. (ch 13.6.1)
typedef struct {
	TickType maxallowedvalue;
	TickType ticksperbase;
	TickType mincycle;
} AlarmBaseType;

// AlarmBaseRefType points to the data type AlarmBaseType. (ch 13.6.1)
typedef AlarmBaseType *AlarmBaseRefType;

// AlarmType represents an alarm object. (ch 13.6.1)
typedef struct {
} AlarmType;

// AppModeType represents the application mode. (ch 13.7.1)
typedef unsigned char AppModeType;

// OSServiceIdType represents the identification of system services. (ch 13.8.1)
typedef struct{} OSServiceIdType;

// StatusType means all status information the API services offer (ch 13.1)
typedef enum {
	E_OK = 0,
	E_OS_ACCESS = 1,
	E_OS_CALLEVEL = 2,
	E_OS_ID = 3,
	E_OS_LIMIT = 4,
	E_OS_NOFUNC = 5,
	E_OS_RESOURCE = 6,
	E_OS_STATE = 7,
	E_OS_VALUE = 8
} StatusType;

// (ch 13.2.4)
const TaskStateType RUNNING;
const TaskStateType WATING;
const TaskStateType READY;
const TaskStateType SUSPENDED;
const TaskType INVALID_TASK;

// (ch 13.4.4)
const ResourceType RES_SCHEDULER;

// (ch 13.6.4)
const TickType OSMAXALLOWEDVALUE;
const TickType OSTICKSPERBASE;
const TickType OSMINCYCLE;

// (ch 13.7.3)
const AppModeType OSDEFAULTAPPMODE;

// (ch 13.2.3.1)
StatusType ActivateTask(TaskType TaskID);

// (ch 13.2.3.2)
StatusType TerminateTask(void);

// (ch 13.2.3.3)
StatusType ChainTask(TaskType TaskID);

// (ch 13.2.3.4)
StatusType Schedule(void);

// (ch 13.2.3.5)
StatusType GetTaskID(TaskRefType TaskID);

// (ch 13.2.3.6)
StatusType GetTaskState(TaskType TaskID, TaskStateRefType State);

// (ch 13.3.2.1)
void EnableAllInterrupts(void);

// (ch 13.3.2.2)
void DisableAllInterrupts(void);

// (ch 13.3.2.3)
void ResumeAllInterrupts(void);

// (ch 13.3.2.4)
void SuspendAllInterrupts(void);

// (ch 13.3.2.5)
void ResumeOSInterrupts(void);

// (ch 13.3.2.6)
void SuspendOSInterrupts(void);

// (ch 13.4.3.1)
StatusType GetResource(ResourceType ResID);

// (ch 13.4.3.2)
StatusType ReleaseResource(ResourceType ResID);

// (ch 13.5.3.1)
StatusType SetEvent(TaskType TaskID, EventMaskType Mask);

// (ch 13.5.3.2)
StatusType ClearEvent(EventMaskType Mask);

// (ch 13.5.3.3)
StatusType GetEvent(TaskType TaskID, EventMaskRefType Event);

// (ch 13.5.3.4)
StatusType WaitEvent(EventMaskType Mask);

// (ch 13.6.3.1)
StatusType GetAlarmBase(AlarmType AlarmID, AlarmBaseRefType Info);

// (ch 13.6.3.2)
StatusType GetAlarm(AlarmType AlarmID, TickRefType Tick);

// (ch 13.6.3.3)
StatusType SetRelAlarm(AlarmType AlarmID, TickType increment, TickType cycle);

// (ch 13.6.3.4)
StatusType SetAbsAlarm(AlarmType AlarmID, TickType start, TickType cycle);

// (ch 13.6.3.5)
StatusType CancelAlarm(AlarmType AlarmID);

// (ch 13.7.2.1)
AppModeType GetActiveApplicationMode(void);

// (ch 13.7.2.2)
void StartOS(AppModeType Mode);

// (ch 13.7.2.3)
void ShutdownOS(StatusType Error);

// (ch 13.8.2.1)
extern void ErrorHook(StatusType Error);

// (ch 13.8.2.2)
extern void PreTaskHook(void);

// (ch 13.8.2.3)
extern void PostTaskHook(void);

// (ch 13.8.2.4)
extern void StartupHook(void);

// (ch 13.8.2.5)
extern void ShutdownHook(StatusType Error);

#endif
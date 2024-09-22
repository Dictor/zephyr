/*
 * Copyright (c) 2024 Jeonghyun Kim <kimdictor@gmail.com>
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/kernel.h>
#include <osek_os.h>

// (ch 13.6.3.1)
StatusType GetAlarmBase(AlarmType AlarmID, AlarmBaseRefType Info)
{
}

// (ch 13.6.3.2)
StatusType GetAlarm(AlarmType AlarmID, TickRefType Tick)
{
}

// (ch 13.6.3.3)
StatusType SetRelAlarm(AlarmType AlarmID, TickType increment, TickType cycle)
{
}

// (ch 13.6.3.4)
StatusType SetAbsAlarm(AlarmType AlarmID, TickType start, TickType cycle)
{
}

// (ch 13.6.3.5)
StatusType CancelAlarm(AlarmType AlarmID)
{
}
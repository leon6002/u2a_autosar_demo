/* PRQA S 3108++ */
/**
 * Copyright (C) 2008-2025 isoft Infrastructure Software Co., Ltd.
 * SPDX-License-Identifier: LGPL-2.1-only-with-exception
 *
 * This library is free software; you can redistribute it and/or modify it under the terms of the
 * GNU Lesser General Public License as published by the Free Software Foundation; version 2.1.
 * This library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 * without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU Lesser General Public License for more details.
 * You should have received a copy of the GNU Lesser General Public License along with this library;
 * if not, write to the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 * or see <https://www.gnu.org/licenses/>.
 */
/* PRQA S 3108-- */



#include "Gpt_Callout.h"

#define GPT_2msCnt		2uL
#define GPT_5msCnt		5uL
#define GPT_10msCnt		10uL
#define GPT_200msCnt	200uL
#define GPT_1000msCnt	1000uL

volatile uint8 Gpt_1msFlag;
volatile uint8 Gpt_2msFlag;
volatile uint8 Gpt_5msFlag;
volatile uint8 Gpt_10msFlag;
volatile uint8 Gpt_200msFlag;
volatile uint8 Gpt_1000msFlag;
volatile uint8 GptDelay = FALSE;
volatile uint32 Delaycount = 0;

static uint32 Gpt_2msTick =0 ;
static uint32 Gpt_5msTick =0 ;
static uint32 Gpt_10msTick =0 ;
static uint32 Gpt_200msTick =0 ;
static uint32 Gpt_1000msTick =0 ;


void GptNotification_1ms(void)
{
	/* 1ms Interrupt*/
	if (GptDelay == TRUE)
	{
		Delaycount++;
	}
	/* 1ms Counter*/
	Gpt_1msFlag = TRUE;
	/* 2ms Counter*/
	Gpt_2msTick++;
	if (Gpt_2msTick >= GPT_2msCnt)
	{
		Gpt_2msTick = 0;
		Gpt_2msFlag = TRUE;
	}

	/* 5ms Counter*/
	Gpt_5msTick++;
	if (Gpt_5msTick >= GPT_5msCnt)
	{
		Gpt_5msTick = 0;
		Gpt_5msFlag = TRUE;
	}

	/* 10ms Counter*/
	Gpt_10msTick++;
	if (Gpt_10msTick >= GPT_10msCnt)
	{
		Gpt_10msTick = 0;
		Gpt_10msFlag = TRUE;
	}
	/* 200ms Counter*/
	Gpt_200msTick++;
	if (Gpt_200msTick >= GPT_200msCnt)
	{
		Gpt_200msTick = 0;
		Gpt_200msFlag = TRUE;
	}
	/* 1000ms Counter*/
	Gpt_1000msTick++;
	if (Gpt_1000msTick >= GPT_1000msCnt)
	{
		Gpt_1000msTick = 0;
		Gpt_1000msFlag = TRUE;
	}
}


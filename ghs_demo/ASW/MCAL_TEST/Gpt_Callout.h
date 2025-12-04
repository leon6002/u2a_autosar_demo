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

#ifndef GPT_CALLOUT_H_
#define GPT_CALLOUT_H_

#include "Gpt.h"

extern volatile uint8 Gpt_1msFlag;
extern volatile uint8 Gpt_2msFlag;
extern volatile uint8 Gpt_5msFlag;
extern volatile uint8 Gpt_10msFlag;
extern volatile uint8 Gpt_200msFlag;
extern volatile uint8 Gpt_1000msFlag;

extern void GptNotification_1ms(void);

#endif /* GPT_CALLOUT_H_ */

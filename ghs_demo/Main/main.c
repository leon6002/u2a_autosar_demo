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
#include "Mcu.h"
#include "r_stbc.h"

#include "Os.h"
#include "Arch_Processor.h"
#include "EcuM.h"

/* All PE, except PE0 stops from continuation, if PE0 did not finish the
 * initialization of shared memory area.
*/
#define SYNC_FLAG 0xdeadbeefu
#pragma ghs startdata
#pragma ghs section data = ".SYNC_FLAG_MULTICORE"
uint32 s_syncFlag = 0;
#pragma ghs section data = default
#pragma ghs enddata

static inline void sync_all_core()                           
{                                            
    ASM("mov _s_syncFlag, r7");              
    ASM("mov 0xdeadbeef, r8");               
    ASM("STSR 0,r6,2");                      
    ASM("cmp R0,r6");                        
    ASM("bne _not_core_init_ram");                           
    ASM("st.w r8, 0[r7]");                   
    ASM("be _core_init_ram");                           
    ASM("_not_core_init_ram:");               
    ASM("ld.w 0[r7],r9");                    
    ASM("cmp r8, r9");                       
    ASM("bne _not_core_init_ram");                           
    ASM("_core_init_ram:");                               
}


int main(void)
{
    
    StatusType status;
    CoreIdType coreId;

    sync_all_core();

    coreId = GetCoreID();
    switch (coreId)
    {
#if (TRUE == CFG_CORE0_AUTOSAROS_ENABLE)
        case OS_CORE_ID_0:
            if (OS_CORE_ID_0 == OS_CORE_ID_MASTER)
            {
                /*Setup Module Standby */
                R_STBC_CfgMsr(MSR_OSTM, 0x00UL);
                R_STBC_CfgMsr(MSR_RSCFD, 0x00UL);

                /* Initialize MCU */
                Mcu_Init(Mcu_Config);
                Mcu_InitClock(McuConf_McuClockSettingConfig_McuClockSettingConfig);
                uint32 LucIntCount = 10000UL;
                while((LucIntCount > 0UL) && (MCU_PLL_LOCKED != Mcu_GetPllStatus()))
                {
                    LucIntCount--;
                }
                Mcu_DistributePllClock();
                
                #if (TRUE == CFG_CORE1_AUTOSAROS_ENABLE)
                StartCore(OS_CORE_ID_1, &status);
                #endif
                #if (TRUE == CFG_CORE2_AUTOSAROS_ENABLE)
                StartCore(OS_CORE_ID_2, &status);
                #endif
                #if (TRUE == CFG_CORE3_AUTOSAROS_ENABLE)
                StartCore(OS_CORE_ID_3, &status);
                #endif

                EcuM_Init();
            }
            break;
#endif

#if (TRUE == CFG_CORE1_AUTOSAROS_ENABLE)
        case OS_CORE_ID_1:
            StartOS(OSDEFAULTAPPMODE);
            break;
#endif

#if (TRUE == CFG_CORE2_AUTOSAROS_ENABLE)
        case OS_CORE_ID_2:
            StartOS(OSDEFAULTAPPMODE);
            break;
#endif

#if (TRUE == CFG_CORE3_AUTOSAROS_ENABLE)
        case OS_CORE_ID_3:
            StartOS(OSDEFAULTAPPMODE);
            break;
#endif

        default: 
            break;
    }

    while (1);
}

void main_PE1(void)
{
    main();
}

void main_PE2(void)
{
    main();
}

void main_PE3(void)
{
    main();
}

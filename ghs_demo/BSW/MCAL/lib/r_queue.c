#include "r_queue.h"
#include <string.h>
void R_Queue_Init(QueueType* const stpMe,void* vdpPool,uint16 u2Max,uint16 u2Step)
{
    stpMe->Pool = vdpPool;
    memset(vdpPool,0U,(u2Max*u2Step));
    stpMe->Size = 0U;
    stpMe->Head = 0U;
    stpMe->Tail = 0U;
    stpMe->Max = u2Max*u2Step;
    stpMe->Step = u2Step;
}
uint8 R_Queue_IsEmpty(QueueType* const stpMe)
{
    return stpMe->Size<=0;
}
uint8 R_Queue_IsFull(QueueType* const stpMe)
{
    return stpMe->Size>=(stpMe->Max/stpMe->Step);
}
uint8 R_Queue_Post(QueueType* const stpMe,void* vdpData)
{
    uint8 Lu1Rtn;
    if(!R_Queue_IsFull(stpMe))
    {
        stpMe->Head = (stpMe->Head + stpMe->Step)%stpMe->Max;
        memcpy((stpMe->Pool+stpMe->Head),vdpData,stpMe->Step);
        stpMe->Size += 1;
	Lu1Rtn = 0U;
    }
    else
    {
	Lu1Rtn = 1U;
    }
    return Lu1Rtn;
}
uint8 R_Queue_Pull(QueueType* const stpMe,void* vdpData)
{
    uint8  Lu1pRtn = 0;
    if(!R_Queue_IsEmpty(stpMe))
    {
        stpMe->Tail = (stpMe->Tail + stpMe->Step)%stpMe->Max;
        memcpy(vdpData,(stpMe->Pool+stpMe->Tail),stpMe->Step);
        stpMe->Size -= 1;
    }
    else
    {
        Lu1pRtn = 1;
    }
    return Lu1pRtn;
}

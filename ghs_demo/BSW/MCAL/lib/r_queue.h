#ifndef _R_QUEUE_H
#define _R_QUEUE_H
#include "r_compiler.h"
typedef struct STag_QueueType
{
    void* Pool;
    uint16 Size;
    uint16 Head;
    uint16 Tail;
    uint16 Max;
    uint16 Step;
}QueueType;
void R_Queue_Init(QueueType* const stpMe,void* vdpPool,uint16 u2Max,uint16 u2Step);
uint8 R_Queue_IsEmpty(QueueType* const stpMe);
uint8 R_Queue_IsFull(QueueType* const stpMe);
uint8 R_Queue_Post(QueueType* const stpMe,void* vdpData);
uint8 R_Queue_Pull(QueueType* const stpMe,void* vdpData);
#endif

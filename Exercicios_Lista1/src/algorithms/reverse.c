#include "reverse.h"

void Algorithm_Reverse_Queue_Using_Stack(Queue * queue, Stack * stack){
    if(Queue_IsEmpty(queue)) return;
    while (!Queue_IsEmpty(queue)){
        Stack_Push(stack, Queue_Dequeue(queue));
    }
    while (!Stack_IsEmpty(stack)){
        Queue_Enqueue(queue,Stack_Pop(stack));
    }
}
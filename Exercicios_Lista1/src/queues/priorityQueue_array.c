#include <stdlib.h>
#include "priorityQueue.h"

struct priorityQueue{
    int head;
    int *values;
    int tail;
    int size;
};

PriorityQueue * PriorityQueue_Create(){
    PriorityQueue * q = (PriorityQueue *) malloc(sizeof(PriorityQueue));
    q->head = 0;
    q->tail = 0;
    q->size = 0;
    q->values = (int *) malloc(sizeof(int) * 100);

    if (q == NULL){
        return NULL;
    }else{
        if(q->values == NULL){
            return NULL;
        }
    }

    return q;
}

void PriorityQueue_Destroy(PriorityQueue * priorityQueue){
    free(priorityQueue->values);  
    free(priorityQueue);
}

bool PriorityQueue_IsEmpty(PriorityQueue * priorityQueue){
    return priorityQueue->size == 0;
}

bool PriorityQueue_IsFull(PriorityQueue * priorityQueue){
    return priorityQueue->size == 100;
}

void PriorityQueue_Enqueue(PriorityQueue * priorityQueue, int value){
    if(!PriorityQueue_IsFull(priorityQueue)){
        int location = findLocation(priorityQueue, value);

        openSpace(priorityQueue, location);

        priorityQueue->values[location] = value;

        (priorityQueue->tail)++;
        (priorityQueue->size)++;

        if(priorityQueue->tail == 100){
            priorityQueue->tail = 0;
        }
    }
}

int PriorityQueue_Dequeue(PriorityQueue * priorityQueue){
   if(!PriorityQueue_IsEmpty(priorityQueue)){ 
        int value = priorityQueue->values[priorityQueue->head];  
        (priorityQueue->head)++;

        if(priorityQueue->head == 100){  
            priorityQueue->head = 0;
        }

        (priorityQueue->size)--;  
        return value;  
    }
   return 0;
}

int findLocation(PriorityQueue * priorityQueue, int value){
    int location = priorityQueue->head;

    while(location != priorityQueue->tail){
        if(priorityQueue->values[location] >= value){
            return location;
        }
        location = (location + 1) % 100;
    }

    return priorityQueue->tail;
}

int openSpace(PriorityQueue * priorityQueue, int location){
    int current = priorityQueue->tail;

    while(current != location){
        int prev = (current - 1 + 100) % 100;
        priorityQueue->values[current] = priorityQueue->values[prev];
        current = prev;
    }

    return location;
}

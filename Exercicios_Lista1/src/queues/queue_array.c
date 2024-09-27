#include <stdlib.h>
#include "queue.h"

struct queue{
    int head;
    int *values;
    int tail;
    int size;
};

Queue * Queue_Create(){
    Queue * q = (Queue *) malloc(sizeof(Queue));
    q->head = 0;
    q->tail = 0;
    q->size = 0;
    q->values = (int *) malloc(sizeof(int) * 100);

    if (q == NULL){
        return NULL;
    }else{
        if(q->values==NULL){
            return NULL;
        }
    }

    return q;
}

void Queue_Destroy(Queue * queue){
    free(queue->values);
    free(queue); 
}

bool Queue_IsEmpty(Queue * queue){
    return queue->size==0;
}

void Queue_Enqueue(Queue * queue, int value){
    if(queue->size != 100){ 
        queue->values[queue->tail] = value;
        (queue->tail)++;

        if(queue->tail == 100){
            queue->tail = 0;
        }

        (queue->size)++;
    }
}

int Queue_Dequeue(Queue * queue){
    if(queue->size != 0){ 
        int value = queue->values[queue->head];  
        (queue->head)++; 

        if(queue->head == 100){  
            queue->head = 0;
        }

        (queue->size)--;  
        return value;  
    }
    return 0;  
}

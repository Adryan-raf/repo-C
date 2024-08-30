#include <stdlib.h>
#include <stdbool.h>

typedef struct{
    int top;
    int * values;
}Stack;

Stack * Stack_Create(){
    Stack * stack = (Stack *) malloc(sizeof(Stack));
    stack->top = 0;
    stack->values = (int *) malloc(sizeof(int) * 100);
    return stack;
}

void Stack_Destroy(Stack * stack){
    free(stack->values);
    free(stack);
}

bool Stack_IsEmpty(Stack * stack){
    return stack ->top == 0;
}

void Stack_Push(Stack * stack, int value){
    *(stack ->values +stack -> top) =value;
    (stack-> top)++;
}

int Stack_Pop(Stack * stack){
    if(!Stack_IsEmpty){
    return 0;
    }
    (stack->top)--;
    int value =*(stack->values + stack->top);   
    return value;
}

int Stack_Peek(Stack * stack){
    return *(stack->values + stack->top-1);
}

#include "sequences.h"

bool Algorithm_Sequences_IsValid(int* pushed, int* popped, int size) {
    Stack* stack = Stack_Create();
    int j = 0;

    for (int i = 0; i < size; i++) {
        Stack_Push(stack, pushed[i]); 

        while (!Stack_IsEmpty(stack) && Stack_Peek(stack) == popped[j]) {
            Stack_Pop(stack);
            j++;
        }
    }

    bool result = Stack_IsEmpty(stack);
    Stack_Destroy(stack);
    return result;
}
#include "../stacks/stack.h"
#include "parenthesis.h"

#define SYMBOL_SIZE 3
char openCharacteres [SYMBOL_SIZE] ={'{','[','('};
char closeCharacteres [SYMBOL_SIZE] ={'}',']',')'};

bool isOpen(char c);
char getClosedFromOpen(char open);

bool Algorithm_Parenthesis_IsValid(char * expression){
    Stack * openedCharacters = Stack_Create();
    
    int i=0;
    char ci;
    while((ci = *(expression + i)) !='\0'){ 
        if (isOpen(ci)) Stack_Push(openedCharacters,ci);
        
        else{
            if(Stack_IsEmpty(openedCharacters)) return false;
            
            char lastOpen = Stack_Pop(openedCharacters);

            if(ci != getClosedFromOpen(lastOpen)) return false;
        }
        i++;
    }
    return Stack_IsEmpty(openedCharacters);
}

bool isOpen(char c){
    for(int i=0;i<SYMBOL_SIZE;i++){
        if (c == openCharacteres[i]) return true;
    }
    return false;
}

char getClosedFromOpen(char open){
    for(int i=0; i < SYMBOL_SIZE; i++){
        if(open == openCharacteres[i]){
            return closeCharacteres [i];
        } 
    }
    return '\0';
}

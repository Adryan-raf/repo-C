P01AbstractDataType# Lista de Exercícios
<img src="../../assets/images/Unicap_Icam_Tech-01.png" alt="drawing" width="200"/>

## Identificação
**Professor**: Dr. Diego Pinheiro

**Disciplina**: Estrutura de Dados 1

**Atividade**: T01StackQueueArray - P01AbstractDataType

## Descrição da Atividade
### Questão 01

Crie um arquivo `stack_array.c` para implementar o `Tipo Abstrato de Dados (TAD) Stack` definido a partir da interface `stack.h`. Na sua implementação, você deve criar uma `struct stack` possuindo como membros uma variável `values` para armazenar os valores da `stack` do tipo ponteiro para inteiros e uma variável `top` para memorizar o topo da pilha. 

```c
struct stack {
    int top;
    int * values;
};
```

Sua implementação deve possuir possuir os métodos:


```c
Stack * Stack_Create();
void Stack_Destroy(Stack *);
bool Stack_IsEmpty(Stack *);
void Stack_Push(Stack *);
int Stack_Pop();
```

### Questão 02
Crie um arquivo `queue_array.c` para implementar o `Tipo Abstrato de Dados (TAD) Queue` definido a partir da interface `queue.h`. Na sua implementação, você deve criar uma `struct queue` possuindo como membros uma variável `values` para armazenar os valores da `queue` do tipo ponteiro para inteiros e uma variável `head` para memorizar o início da `queue` e uma variável `tail` para memorizar o fim da `queue`. Caso ajude, adicione uma variável `size` também. 

```c
struct queue {
    int head;
    int tail;
    int size;
    int * values;
};
```


Sua implementação deve possuir possuir os métodos:


```c
Queue * Queue_Create();
void Queue_Destroy(Queue * queue);
bool Queue_IsEmpty(Queue * queue);
void Queue_Enqueue(Queue * queue, int value);
int Queue_Dequeue(Queue * queue);
```

### Questão 03
Crie um arquivo `reverse.c` para implementar um método que reverte os valores de uma `queue` utilizando apenas uma `stack` como apoio e nada mais. O protótipo do método deve estar no arquivo `reverse.h` conforme a seguir: 
```c
void Algorithm_Reverse_Queue_Using_Stack(Queue * queue, Stack * stack);
```


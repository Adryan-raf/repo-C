P01AbstractDataType# Lista de Exercícios
<img src="../../assets/images/Unicap_Icam_Tech-01.png" alt="drawing" width="200"/>

## Identificação
**Professor**: Dr. Diego Pinheiro

**Disciplina**: Estrutura de Dados 1

**Atividade**: T01StackQueueArray - P03StackSequences

## Descrição da Atividade
### Questão 01 (Leet Code 946. Validate Stack Sequences)
Dado dois vetores de inteiros `pushed` and `popped`, cada um com valores distintos, retorne `true` *caso essa vatores poderiam ter sido o resultado de uma sequência de métodos `push` and `pop` em uma pilha inicialmente vazia *, or `false` *caso contrário*.

Implemente o método
```java
boolean validateStackSequences(int[] pushed, int[] popped)
```

**Exemplo 1**

```java
pushed = [1,2,3,4,5]
popped = [4,5,3,2,1]
```
```java
validateStackSequences(pushed, popped)
```
retorna 
```java
true
```

**Explicação**

    Nós podemos realizar a seguinte sequência de operações:
    push(1), push(2), push(3), push(4),
    pop() -> 4,
    push(5),
    pop() -> 5, pop() -> 3, pop() -> 2, pop() -> 1


**Exemplo 2**
```java
pushed = [1,2,3,4,5]
popped = [4,3,5,1,2]
```
```java
validateStackSequences(pushed, popped)
```
retorna 
```java
false
```

**Explicação**

    O valor `1` não pode ser desempilhado (ie., `popped`) antes do valor 2.

### Restrições

- 1 <= `pushed.length` <= 1000
- 0 <= `pushed[i]` <= 1000
- Todos os elementos do vetor `pushed` são **únicos**.
- `popped.length` == `pushed.length`
- `popped` é uma permutação de `pushed`.

**Dica**
Para lhe ajudar, crie, na `StackArray`, o método
```java 
int peek()
```
que retorna o último elemento da pilha sem retirá-lo da pilha.


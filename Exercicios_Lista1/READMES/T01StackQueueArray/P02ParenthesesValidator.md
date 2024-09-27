P01AbstractDataType# Lista de Exercícios
<img src="../../assets/images/Unicap_Icam_Tech-01.png" alt="drawing" width="200"/>

## Identificação
**Professor**: Dr. Diego Pinheiro

**Disciplina**: Estrutura de Dados 1

**Atividade**: T01StackQueueArray - P02ParenthesesValidator

## Descrição da Atividade
### Questão 01
Implemente o arquivo `parenthesis.c` para implementar um método 

```c
bool Algorithm_Parenthesis_IsValid(char * expression){
```

que recebe uma variável `expression` do tipo ponteiro para `char` e retorna `true` caso `expression` contenha uma expressão válida e `false` caso contrário.

Uma expressão é válida se:

- Parenteses `(` abertos devem ser fechados por parênteses `)`, colchetes `[` por colchetes `]`, e chaves `{` por chaves `}`;

Por exemplo, as seguintes expressão são válidas
- `(` `)`
- `(` `)` `[` `]` `{` `}`
- `(` `[` `{` `}` `]` `)`

E as seguintes expressões são inválidas 
- `)`
- `(` `[` `}` `]`
- `(` `[` `]` `)` `{`

> Uma `Stack` ou `Queue` implementada pode ajudar uma vez que existe uma compatibilidade entre os tipos `int` e `char`.
> Armazene os parenteses, conchetes e chaves abertos `(` `[` `{` em uma varíavel global.
> Armazene os parenteses, conchetes e chaves fechados `)` `]` `}` em uma varíavel global.
> Modularize o código criando os métodos 


```c
bool isOpen(char character) 
```
que retorna `true` caso `character` seja um parêntese, conchete ou chave aberta `(` `[` `{`  e 

```c
char getOpen(char closeCharacter) 
```

que a partir de um `closeCharacter` igual a `)` `]` `}` retorna um `char` com o respectivo parêntese, conchetes e chaves aberto `(` `[` `{`.
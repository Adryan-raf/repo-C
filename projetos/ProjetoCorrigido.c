#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_TOKENS 1000
#define MAX_SIMBOLOS 1000

// Definição dos tipos de token
enum TipoToken {
    TOKEN_NUM_INT,
    TOKEN_NUM_DEC,
    TOKEN_ID,
    TOKEN_LITERAL, 
    TOKEN_PALAVRA_RESERVADA,
    TOKEN_OPERADOR_ARITMETICO,
    TOKEN_OPERADOR_ATRIBUICAO,
    TOKEN_OPERADOR_LOGICO,
    TOKEN_OPERADOR_COMPARACAO,
    TOKEN_SIMBOLO_ESPECIAL,
    TOKEN_COMENTARIO,
    TOKEN_ERRO
};

// Estrutura de Token
typedef struct {
    enum TipoToken tipo;
    char valor[100];
} Token;

// Estrutura para Tabela de Símbolos
typedef struct {
    char simbolo[100];
} Simbolo;

// Listas globais para armazenar tokens e símbolos
Token lista_tokens[MAX_TOKENS];
Simbolo lista_simbolos[MAX_SIMBOLOS];
int num_tokens = 0;
int num_simbolos = 0;

// Função para criar um token
Token criar_token(enum TipoToken tipo, const char *valor) {
    Token t;
    t.tipo = tipo;
    strcpy(t.valor, valor);
    return t;
}

// Função para adicionar um símbolo à tabela de símbolos e retornar o índice
int adicionar_simbolo(const char *valor) {
    // Verificar se o símbolo já está na tabela
    for (int i = 0; i < num_simbolos; i++) {
        if (strcmp(lista_simbolos[i].simbolo, valor) == 0) {
            return i + 1; // Retorna o índice (base 1)
        }
    }

    // Caso contrário, adiciona o símbolo
    strcpy(lista_simbolos[num_simbolos].simbolo, valor);
    num_simbolos++;
    return num_simbolos; // Retorna o novo índice
}

// Função para imprimir um token
void imprimir_token(Token t) {
    switch (t.tipo) {
        case TOKEN_NUM_INT:
            printf("(NUM_INT, %s)\n", t.valor);
            break;
        case TOKEN_NUM_DEC:
            printf("(NUM_DEC, %s)\n", t.valor);
            break;
        case TOKEN_ID:
            printf("(ID, %s)\n", t.valor);
            break;
        case TOKEN_LITERAL:
            printf("(Literal, \"%s\")\n", t.valor); 
            break;
        case TOKEN_PALAVRA_RESERVADA:
            printf("(Palavra Reservada, %s)\n", t.valor);
            break;
        case TOKEN_OPERADOR_ARITMETICO:
        case TOKEN_OPERADOR_ATRIBUICAO:
        case TOKEN_OPERADOR_LOGICO:
        case TOKEN_OPERADOR_COMPARACAO:
            printf("(Operador, %s)\n", t.valor);
            break;
        case TOKEN_SIMBOLO_ESPECIAL:
            printf("(Símbolo Especial, %s)\n", t.valor);
            break;
        case TOKEN_COMENTARIO:
            printf("(Comentário, %s)\n", t.valor);
            break;
        case TOKEN_ERRO:
            printf("(Erro, %s)\n", t.valor);
            break;
        default:
            printf("(Desconhecido, %s)\n", t.valor);
            break;
    }
}

// Função para verificar se é uma palavra reservada
int eh_palavra_reservada(const char* palavra) {
    const char* palavras_reservadas[] = {
        "int", "float", "char", "boolean", "void", "if", "else", "for", "while", 
        "scanf", "println", "main", "return", "printf","include"
    };
    for (int i = 0; i < 15; i++) {
        if (strcmp(palavra, palavras_reservadas[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

// Função para verificar operadores aritméticos
int eh_operador_aritmetico(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '%');
}

// Função para verificar operadores de comparação
int eh_operador_comparacao(const char* op) {
    const char* operadores[] = { "==", "!=", ">=", "<=", ">", "<" };
    for (int i = 0; i < 6; i++) {
        if (strcmp(op, operadores[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

// Função para verificar operadores lógicos
int eh_operador_logico(const char* op) {
    return (strcmp(op, "&&") == 0 || strcmp(op, "||") == 0 || strcmp(op, "!") == 0 || strcmp(op, "&") == 0);
}

// Função para obter o próximo token
Token proximo_token(const char* codigo, int* pos) {
    while (isspace(codigo[*pos])) {
        (*pos)++; // Pular espaços em branco e quebras de linha
    }
    
    char c = codigo[*pos];
    
    if (c == '\0') {
        Token t;
        t.tipo = TOKEN_ERRO;
        strcpy(t.valor, "");
        return t;
    }
    
    // Números inteiros e decimais
    if (isdigit(c)) {
        char buffer[100];
        int i = 0;
        while (isdigit(codigo[*pos])) {
            buffer[i++] = codigo[*pos];
            (*pos)++;
        }
        if (codigo[*pos] == '.') {
            buffer[i++] = '.';
            (*pos)++;
            while (isdigit(codigo[*pos])) {
                buffer[i++] = codigo[*pos];
                (*pos)++;
            }
            buffer[i] = '\0';
            return criar_token(TOKEN_NUM_DEC, buffer);
        } else {
            buffer[i] = '\0';
            return criar_token(TOKEN_NUM_INT, buffer);
        }
    }

    // Identificadores e palavras reservadas
    if (isalpha(c) || c == '_') {
        char buffer[100];
        int i = 0;
        while (isalnum(codigo[*pos]) || codigo[*pos] == '_') {
            buffer[i++] = codigo[*pos];
            (*pos)++;
        }
        buffer[i] = '\0';
        
        if (eh_palavra_reservada(buffer)) {
            return criar_token(TOKEN_PALAVRA_RESERVADA, buffer);
        } else {
            int indice = adicionar_simbolo(buffer);
            char indice_str[10];
            sprintf(indice_str, "%d", indice);
            return criar_token(TOKEN_ID, indice_str);
        }
    }

    // Strings de texto (entre aspas)
    if (c == '"') {
        char buffer[100];
        int i = 0;
        (*pos)++; // Pular o caractere inicial de aspas
        while (codigo[*pos] != '"' && codigo[*pos] != '\0') {
            buffer[i++] = codigo[*pos];
            (*pos)++;
        }
        if (codigo[*pos] == '"') {
            (*pos)++; // Pular a aspas final
        }
        buffer[i] = '\0';
        return criar_token(TOKEN_LITERAL, buffer); // Literal, não adiciona à tabela de símbolos
    }

    // Comentários
    if (c == '/' && codigo[*pos + 1] == '/') {
        char buffer[100];
        int i = 0;
        while (codigo[*pos] != '\n' && codigo[*pos] != '\0') {
            buffer[i++] = codigo[*pos];
            (*pos)++;
        }
        buffer[i] = '\0';
        return criar_token(TOKEN_COMENTARIO, buffer);
    }

    // Operadores aritméticos
    if (eh_operador_aritmetico(c)) {
        char buffer[2] = { codigo[*pos], '\0' };
        (*pos)++;
        return criar_token(TOKEN_OPERADOR_ARITMETICO, buffer);
    }

    // Operadores de atribuição
    if (c == '=') {
        if (codigo[*pos + 1] == '=') {
            (*pos) += 2;
            return criar_token(TOKEN_OPERADOR_COMPARACAO, "==");
        } else {
            (*pos)++;
            return criar_token(TOKEN_OPERADOR_ATRIBUICAO, "=");
        }
    }

    // Operadores lógicos e comparativos
    if (codigo[*pos] == '&' && codigo[*pos + 1] == '&') {
        (*pos) += 2;
        return criar_token(TOKEN_OPERADOR_LOGICO, "&&");
    }
    if (codigo[*pos] == '|' && codigo[*pos + 1] == '|') {
        (*pos) += 2;
        return criar_token(TOKEN_OPERADOR_LOGICO, "||");
    }
    if (codigo[*pos] == '!' && codigo[*pos + 1] == '=') {
        (*pos) += 2;
        return criar_token(TOKEN_OPERADOR_COMPARACAO, "!=");
    }
    if (eh_operador_comparacao(&codigo[*pos])) {
        char buffer[3] = { codigo[*pos], codigo[*pos + 1], '\0' };
        (*pos) += strlen(buffer);
        return criar_token(TOKEN_OPERADOR_COMPARACAO, buffer);
    }

    // Símbolos especiais
    if (c == '(' || c == ')' || c == '{' || c == '}' || c == '[' || c == ']' || c == ';' || c == ',') {
        char buffer[2] = { codigo[*pos], '\0' };
        (*pos)++;
        return criar_token(TOKEN_SIMBOLO_ESPECIAL, buffer);
    }

    // Token desconhecido
    char buffer[2] = { codigo[*pos], '\0' };
    (*pos)++;
    return criar_token(TOKEN_ERRO, buffer);
}

// Função principal
int main() {
    char codigo[1000]; // Buffer para armazenar a entrada do usuário
    int pos = 0;
    Token t;

    // Solicitar que o usuário insira o código
    printf("Digite o código para análise: ");
    fgets(codigo, sizeof(codigo), stdin);  // Lê uma linha inteira de até 999 caracteres

    // Remover a quebra de linha capturada pelo fgets, se presente
    size_t len = strlen(codigo);
    if (codigo[len - 1] == '\n') {
        codigo[len - 1] = '\0';
    }

    // Analisando o código até o final
    while (codigo[pos] != '\0') {
        t = proximo_token(codigo, &pos);

        // Armazenar o token na lista de tokens
        lista_tokens[num_tokens++] = t;

        // Imprimir o token
        imprimir_token(t);
        
        // Verificar se houve um erro no reconhecimento do token
        if (t.tipo == TOKEN_ERRO && strlen(t.valor) > 0) {
            printf("Erro: Token desconhecido '%s'\n", t.valor);
        }
    }

    // Imprimir tabela de símbolos
    printf("\nTabela de Símbolos:\n");
    for (int i = 0; i < num_simbolos; i++) {
        printf("%d: %s\n", i + 1, lista_simbolos[i].simbolo);
    }

    return 0;
}

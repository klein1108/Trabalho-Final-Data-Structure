#ifndef CONSTANTS_H_INCLUDED
#define CONSTANTS_H_INCLUDED

#define TRUE 1
#define FALSE 0

#define MAX_CHAR_SENHA 10
#define MAX 9

// ASCII: 32 = ESPACE
#define ASCII_INICIO 33
#define ASCII_FIM 126


#define TOTAL_SENHAS_BUSCA 10

#define WRITE "w"

typedef struct {
    int id;
    char dado[MAX_CHAR_SENHA];
} Senha;

#endif // CONSTANTS_H_INCLUDED

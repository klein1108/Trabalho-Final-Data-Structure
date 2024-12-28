#include "geradorArquivos.h"

char selecionaCharAleatorio(){
    int random = ASCII_INICIO + rand() % (ASCII_FIM - ASCII_INICIO + 1);
    char caractere = (char)random;
    return caractere;
}

Senha criaUmaSenhaAleatoriaPorId(int id){
    Senha newSenha;
    char password[MAX_CHAR_SENHA] = "";

    for(int i = 0; i <= (MAX_CHAR_SENHA - 1); i++){
        password[i] = selecionaCharAleatorio();
    }
    password[MAX_CHAR_SENHA-1] = '\0';

    newSenha.id = id;
    strcpy(newSenha.valor, password);

    return newSenha;
}

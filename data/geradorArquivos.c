#include "geradorArquivos.h"

char selecionaCharAleatorio() {
    int random = ASCII_INICIO + rand() % (ASCII_FIM - ASCII_INICIO + 1);
    char caractere = (char)random;
    return caractere;
}

Senha criaUmaSenhaAleatoriaPorId(int id) {
    Senha newSenha;
    char password[MAX_CHAR_SENHA] = "";

    for(int i = 0; i <= (MAX_CHAR_SENHA - 1); i++) {
        password[i] = selecionaCharAleatorio();
    }
    password[MAX_CHAR_SENHA-1] = '\0';

    newSenha.id = id;
    strcpy(newSenha.dado, password);

    return newSenha;
}

void criaArquivoNomeadoComTotalDeSenhas(char nomeArquivo[], int total) {
    FILE *file;
    Senha senha[total];

    file = fopen(nomeArquivo, WRITE);

    if(file == NULL) {
        printf("Erro ao abrir arquivo: %s", nomeArquivo);
    } else {

        for(int i = 1; i <= total; i++) {
            senha[i] = criaUmaSenhaAleatoriaPorId(i);
            fprintf(file, "%d;%s\n", senha[i].id, senha[i].dado);
        }

        printf(" O Arquivo \"%s\" foi criado com sucesso!\n", nomeArquivo);
        fclose(file);
    }

}

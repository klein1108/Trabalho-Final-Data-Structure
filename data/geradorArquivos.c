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

void criaTotalDeSenhas(Senha senhas[], int total){

    for(int i = 0; i < total; i++){
        senhas[i] = criaUmaSenhaAleatoriaPorId(i+1);
    }

}

void criaArquivoNomeadoOrdenadoComTotalDeSenhas(char nomeArquivo[], Senha senhas[], int total) {
    FILE *file;

    file = fopen(nomeArquivo, WRITE);

    if(file == NULL) {
        printf("Erro ao abrir arquivo: %s", nomeArquivo);
    } else {

        for(int i = 0; i < total; i++) {
            fprintf(file, "%d;%s\n", senhas[i].id, senhas[i].dado);
        }

        printf(" O Arquivo \"%s\" foi criado com sucesso!\n", nomeArquivo);
        fclose(file);
    }

}

void criaArquivoNomeadoDesordenadoComTotalDeSenhas(char nomeArquivo[], Senha senhas[], int total){
    FILE *file;

    int faltantes = total;
    int indexRandom;

    file = fopen(nomeArquivo, WRITE);

    if(file == NULL) {
        printf("Erro ao abrir arquivo: %s", nomeArquivo);
    } else {

        for(int i = 0; i < total; i++) {
            //sorteia index entre 0 e faltantes
            indexRandom =  rand() % (faltantes + 1);
            printf("INDEXRANDOM = %d\n", indexRandom);

            //escreve no arquivo
            fprintf(file, "%d;%s\n", senhas[indexRandom].id, senhas[indexRandom].dado);

            //retira do array

            for(int k = 0, l = 0; k < faltantes; k++, l++){
                if(k == indexRandom){
                    l++;
                }

                if(l < faltantes){
                    senhas[k].id = senhas[l].id;
                    strcpy(senhas[k].dado, senhas[l].dado);
                }
            }

            //subtrai faltantes
            faltantes--;

        }

        printf(" O Arquivo \"%s\" foi criado com sucesso!\n", nomeArquivo);
        fclose(file);
    }

}

#include"lista.h"

ListaSenhaNodo* criaUmaListaDeSenhaVazia() {
    return NULL;
}

ListaSenhaNodo* insereSenhaNodoNaLista(ListaSenhaNodo* senhaAntes, Senha dadosSenha) {

    ListaSenhaNodo *novaSenha = (ListaSenhaNodo*) malloc(sizeof(ListaSenhaNodo));
    novaSenha->data.id = dadosSenha.id;
    strcpy(novaSenha->data.dado, dadosSenha.dado);
    novaSenha->prox = NULL;

    ListaSenhaNodo *senhaAtual = senhaAntes;

    if (senhaAtual == NULL) {
        return novaSenha;
    }

    while (senhaAtual->prox != NULL) {
        senhaAtual = senhaAtual->prox;
    }

    senhaAtual->prox = novaSenha;

    return senhaAntes;
}

ListaSenhaNodo* encontraSenhaNodoNaListaPorId(ListaSenhaNodo* lista, int id){
    ListaSenhaNodo *listaAtual = lista;

    while(listaAtual != NULL && listaAtual->data.id != id) {
        listaAtual = listaAtual->prox;
    }

    // retorna Id ou NULL
    return listaAtual;
}

ListaSenhaNodo* getListaPopuladaPorNomeArquivo(char nomeArquivo[]){

    ListaSenhaNodo* listaSenhaNodo = criaUmaListaDeSenhaVazia();
    Senha senhaColetada;

    int idToInteger = 0;
    char idToString[MAX_CHAR_SENHA] = "";
    char senhaArquivo[MAX_CHAR_SENHA] = "";
    int i = 0, j = 0;
    char ch = ' ';


    FILE *file;
    file = fopen(nomeArquivo, "r");


    if (file == NULL) {
        printf("Erro ao abrir arquivo\n!");
    } else {

        do{

            //limpa valores de ID para proxima busca
            strcpy(idToString, "");
            i = 0;

            //limpa valores de Senha para proxima busca
            strcpy(senhaArquivo, "");
            j = 0;


            //get valor do id em string
            do {
                ch = getc(file);

                if (ch != FIM_INDEX && ch != EOF) {
                    idToString[i] = ch;
                    i++;
                }

            } while (ch != FIM_INDEX && ch != EOF);

            //converte de string para inteiro
            idToString[i] = FIM_STRING;
            idToInteger = atoi(idToString);

            //get valor de senha em string
            do {
                ch = getc(file);

                if (ch != NOVA_LINHA && ch != EOF) {
                    senhaArquivo[j] = ch;
                    j++;
                }

            } while (ch != NOVA_LINHA && ch != EOF);

            //passa dado para senha
            senhaColetada.id = idToInteger;
            strcpy(senhaColetada.dado, senhaArquivo);

            if (idToInteger != 0) {
                listaSenhaNodo = insereSenhaNodoNaLista(listaSenhaNodo, senhaColetada);
                printf("DADO (id: %d) [senha:\"\%s\"] coletado com sucesso!\n\n", senhaColetada.id, senhaColetada.dado);
            }


        } while(ch != EOF);

        fclose(file);
        printf("Dados coletados com sucesso!\n");
    }

    return listaSenhaNodo;

}

void analizaListaSenhas(char dataFileName[], char resultsFileName[], ListaSenhaNodo *listaSenhas){
    FILE *fileDestiny;
    FILE *fileSource;

    Senha senhaColetada;
    ListaSenhaNodo* teste;
    int idToInteger = 0;
    char idToString[MAX_CHAR_SENHA] = "";
    char senhaArquivo[MAX_CHAR_SENHA] = "";
    int i = 0, j = 0;
    char ch = ' ';

    clock_t secondsBegin;
    clock_t secondsEnd;
    double time_ms;
    clock_t seconds1;
    clock_t seconds2;
    double time_ms_2;

    fileSource = fopen(dataFileName, "r");
    fileDestiny = fopen(resultsFileName, "w");

    if (fileSource == NULL || fileDestiny == NULL) {
        printf("Error opening file!\n");
    } else {

        secondsBegin = clock();

        do{

            //limpa valores de ID para proxima busca
            strcpy(idToString, "");
            i = 0;

            //limpa valores de Senha para proxima busca
            strcpy(senhaArquivo, "");
            j = 0;


            //get valor do id em string
            do {
                ch = getc(fileSource);

                if (ch != FIM_INDEX && ch != EOF) {
                    idToString[i] = ch;
                    i++;
                }

            } while (ch != FIM_INDEX && ch != EOF);

            //converte de string para inteiro
            idToString[i] = FIM_STRING;
            idToInteger = atoi(idToString);

            //get valor de senha em string
            do {
                ch = getc(fileSource);

                if (ch != NOVA_LINHA && ch != EOF) {
                    senhaArquivo[j] = ch;
                    j++;
                }

            } while (ch != NOVA_LINHA && ch != EOF);

            //passa dado para senha
            senhaColetada.id = idToInteger;
            strcpy(senhaColetada.dado, senhaArquivo);

            if (idToInteger != 0) {
                seconds1 = clock();

                teste = encontraSenhaNodoNaListaPorId(listaSenhas, idToInteger);

                seconds2 = clock();

                time_ms_2 = (double)(seconds2 - seconds1) / CLOCKS_PER_SEC * 1000;

                if (teste != NULL && (strcmp(teste->data.dado, senhaArquivo) == 0)) {
                    fprintf(fileDestiny, "%d - OK! [%.3f]\n", teste->data.id, teste->data.dado, time_ms_2);
                }
                else {
                    fprintf(fileDestiny, "%d - ERROR! [%.3f]\n", teste->data.id, teste->data.dado, time_ms_2);
                }
            }

        } while(ch != EOF);

        secondsEnd = clock();
        time_ms = (double)(secondsEnd - secondsBegin) / CLOCKS_PER_SEC * 1000;

        fprintf(fileDestiny, "%.3f\n", time_ms);

        fclose(fileSource);
        fclose(fileDestiny);
        printf("Dados coletados com sucesso!\n");
    }
}





void destroiListaDeSenha(ListaSenhaNodo *listaAtual){
    ListaSenhaNodo *lista = listaAtual;
    ListaSenhaNodo *aux = listaAtual;

    while (lista != NULL) {
        aux = lista;
        lista = lista->prox;
        free(aux);
    }
    printf("\n\tLista Destruida com sucesso!\n");
}

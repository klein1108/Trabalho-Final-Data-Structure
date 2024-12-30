#include"lista.h"

ListaSenhaNodo* criaUmaListaDeSenhaVazia() {
    return NULL;
}

ListaSenhaNodo* insereSenhaNodoNaLista(ListaSenhaNodo* senhaAntes, Senha dadosSenha) {

    printf("DADOS_SENHA.ID = %d  E DADOS_SENHA.DADO = \"%s\"\n\n", dadosSenha.id, dadosSenha.dado);
    printf("SENHA_ANTES->DATA.ID = %d  E SENHA_ANTES->DATA.DADO = \"%s\"\n\n", senhaAntes->data.id, senhaAntes->data.dado);
    ListaSenhaNodo *novaSenha = (ListaSenhaNodo*) malloc(sizeof(ListaSenhaNodo*));
    novaSenha->data.id = dadosSenha.id;
    strcpy(novaSenha->data.dado, dadosSenha.dado);
    novaSenha->prox = NULL;

    ListaSenhaNodo *senhaAtual = senhaAntes;

//    printf("SENHA ATUAL (id: %d) [senha:\"\%s\"] coletado com sucesso!\n", senhaAtual->data.id, senhaAtual->data.dado);
//    printf("SENHA ANTES (id: %d) [senha:\"\%s\"] coletado com sucesso!\n\n", senhaAntes->data.id, senhaAntes->data.dado);

    if (senhaAtual == NULL) {
        return novaSenha;
    }
    printf("AQUI 2!!!\n");
    while (senhaAtual->prox != NULL) {
        senhaAtual = senhaAtual->prox;
        printf("WHILE\n");
    }
    printf("AQUI 3!!!\n");


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
    }
    else {

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

//            printf("SENHA.ID = %d E SENHA.DADO = \"%s\"\n", senhaColetada.id, senhaColetada.dado);

            if (idToInteger != 0) {
                printf("AQUI\n");
                listaSenhaNodo = insereSenhaNodoNaLista(listaSenhaNodo, senhaColetada);
                printf("DADO (id: %d) [senha:\"\%s\"] coletado com sucesso!\n\n", senhaColetada.id, senhaColetada.dado);
            }


        } while(ch != EOF);

        fclose(file);
        printf("Dados coletados com sucesso!\n");
    }

    return listaSenhaNodo;

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

#include "data/geradorArquivos.h"
#include "lista/lista.h"

int main(){
    srand(time(NULL));

    int total = 1000;

    Senha senhas[1000];

    criaTotalDeSenhas(senhas, total);
    criaArquivoNomeadoOrdenadoComTotalDeSenhas("SenhaArquivoOrdenado.txt", senhas, total);
//    criaArquivoNomeadoDesordenadoComTotalDeSenhas("SenhaArquivoDesordenado.txt", senhas, total);


    ListaSenhaNodo *lista = criaUmaListaDeSenhaVazia();
//    lista = insereSenhaNodoNaLista(lista, senhas[0]);
//    lista = insereSenhaNodoNaLista(lista, senhas[1]);
//    printf("LISTA NODO 1:\nID = %d\nSenha:\"%s\"\n\n", lista->data.id, lista->data.dado);
//    printf("LISTA NODO PROX:\nID = %d\nSenha:\"%s\"\n\n", lista->prox->data.id, lista->prox->data.dado);
//
//    printf("\nENCONTRE SENHA DE ID = 2\n");
//
//    printf("SENHA: \"%s\"\n",
//           encontraSenhaNodoNaListaPorId(lista, 2)->data.dado
//    );
    lista = getListaPopuladaPorNomeArquivo("SenhaArquivoOrdenado.txt");


    destroiListaDeSenha(lista);
    return 0;

}

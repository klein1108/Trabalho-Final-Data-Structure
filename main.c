#include "data/geradorArquivos.h"
#include "lista/lista.h"

int main(){
    srand(time(NULL));

    int total = 1000;

    Senha senhas[1000];

    criaTotalDeSenhas(senhas, total);
    criaArquivoNomeadoOrdenadoComTotalDeSenhas("SenhaArquivoOrdenado.txt", senhas, total);
    criaArquivoNomeadoOrdenadoComTotalDeSenhas("SenhaArquivoDesordenado.txt", senhas, total);

    ListaSenhaNodo *lista = criaUmaListaDeSenhaVazia();
    ListaSenhaNodo *listaBusca = criaUmaListaDeSenhaVazia();

    lista = getListaPopuladaPorNomeArquivo("SenhaArquivoOrdenado.txt");


    criaArquivoBuscaSenha("buscaSenhasCorretas.txt", senhas, total);
    criaArquivoBuscaSenhaCinquentaPorcentoErradas("buscaSenhas50PorcentoIncorretas.txt", senhas, total);
    criaArquivoBuscaSenhaOitentaPorcentoErradas("buscaSenhas80PorcentoInorretas.txt", senhas, total);

//    lista = encontraSenhaNodoNaListaPorId(lista, 55);

//    listaBusca = getListaPopuladaPorNomeArquivo("buscaSenhas80PorcentoInorretas.txt");

    analizaListaSenhas("buscaSenhasCorretas.txt", "AnalizaCorretos.txt", lista);
    analizaListaSenhas("buscaSenhas50PorcentoIncorretas.txt", "Analiza50PorcentoIncorretos.txt", lista);
    analizaListaSenhas("buscaSenhas80PorcentoInorretas.txt", "Analiza80PorcentoIncorretos.txt", lista);


    destroiListaDeSenha(lista);
    destroiListaDeSenha(listaBusca);
    return 0;

}

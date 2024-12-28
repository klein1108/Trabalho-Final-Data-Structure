#include "data/geradorArquivos.h"

int main(){
    srand(time(NULL));
    Senha senhas[1000];
    int total = 1000;

    criaTotalDeSenhas(senhas, total);

//    criaArquivoNomeadoOrdenadoComTotalDeSenhas("SenhaArquivoOrdenado.txt", senhas, total);

    criaArquivoNomeadoDesordenadoComTotalDeSenhas("SenhaArquivoDesordenado.txt", senhas, total);

    return 0;

}

#include "geradorArquivos.h"

int main(){
    srand(time(NULL));
    Senha senhas [100];
    for(int i = 0; i < 100; i++){
        senhas[i] = criaUmaSenhaAleatoriaPorId(i+1);
        printf("%d, %s\n",senhas[i].id, senhas[i].valor);
    }
    return 0;
}

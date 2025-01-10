#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "../constants.h"

char selecionaCharAleatorio();
Senha criaUmaSenhaAleatoriaPorId(int id);
void criaTotalDeSenhas(Senha senhas[], int total);
void criaArquivoNomeadoOrdenadoComTotalDeSenhas(char nomeArquivo[], Senha senhas[], int total);
void criaArquivoNomeadoDesordenadoComTotalDeSenhas(char nomeArquivo[], Senha senhas[], int total);
void criaArquivoBuscaSenha(char nomeArquivo[], Senha senhas[], int tamanhoLista);
void criaArquivoBuscaSenhaCinquentaPorcentoErradas(char nomeArquivo[], Senha senhas[], int tamanhoLista);
void criaArquivoBuscaSenhaOitentaPorcentoErradas(char nomeArquivo[], Senha senhas[], int tamanhoLista);

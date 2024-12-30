#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include"../constants.h"

#define FIM_INDEX ';'
#define FIM_STRING '\0'
#define NOVA_LINHA '\n'

typedef struct tipoListaSenhaNodo{
    Senha data;
    struct tipoListaSenhaNodo *prox;
} ListaSenhaNodo;

ListaSenhaNodo* criaUmaListaDeSenhaVazia();
ListaSenhaNodo* insereSenhaNodoNaLista(ListaSenhaNodo* primeiroNodo, Senha dadosSenha);
ListaSenhaNodo* encontraSenhaNodoNaListaPorId(ListaSenhaNodo* lista, int id);
ListaSenhaNodo* getListaPopuladaPorNomeArquivo(char nomeArquivo[]);

void destroiListaDeSenha(ListaSenhaNodo *lista);

#endif // LISTA_H_INCLUDED

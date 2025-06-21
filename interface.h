#ifndef INTERFACE_H_INCLUDED
#define INTERFACE_H_INCLUDED
#include "fila.h"
#include <stdio.h>
#include <stdlib.h>

typedef int Item;
// Estrutura de um no na lista de adjacencia
typedef struct lista {
    Item item;               // Armazena o destino da aresta
    struct lista* next;      // Ponteiro para o próximo nó da lista
} lista;
typedef struct lista *_list;

// Estrutura do grafo
typedef struct {
    int vertices;           // Numero total de vertices
    _list* listaAdj;        // Vetor de ponteiros para as listas de adjacencia
} Grafo;

lista *novoNo(Item item);
Grafo *criarGrafo(int vertices);
void adicionarAresta(Grafo *grafo, int origem, int destino);



#endif // INTERFACE_H_INCLUDED

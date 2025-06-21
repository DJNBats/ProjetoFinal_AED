#ifndef INTERFACE_H_INCLUDED
#define INTERFACE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

typedef int Item;
// Estrutura de um nó na lista de adjacência
typedef struct lista {
    Item item;               // Armazena o destino da aresta
    struct lista* next;      // Ponteiro para o próximo nó da lista
} lista;
typedef struct lista *_list;

// Estrutura do grafo
typedef struct {
    int vertices;           // Número total de vértices
    _list* listaAdj;        // Vetor de ponteiros para as listas de adjacência
} Grafo;

lista *novoNo(Item item);
Grafo *criarGrafo(int vertices);
void adicionarAresta(Grafo *grafo, int origem, int destino);



#endif // INTERFACE_H_INCLUDED

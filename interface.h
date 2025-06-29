#ifndef INTERFACE_H_INCLUDED
#define INTERFACE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

typedef int Item;
// Estrutura de um nó na lista de adjacência
typedef struct no {
    Item item;               // Armazena o destino da aresta
    struct no* next;      // Ponteiro para o próximo nó da lista
} lista;


// Estrutura do grafo
typedef struct {
    int vertices;           // Número total de vértices
    lista** listaAdj;        // Vetor de ponteiros para as listas de adjacência
} Grafo;

lista *novoNo(Item item);
Grafo *criarGrafo(int vertices);
void adicionarAresta(Grafo *grafo, int origem, int destino, int dirigido);

// Função de busca em largura (BFS)
void BFS(Grafo *grafo, int inicio);


#endif // INTERFACE_H_INCLUDED

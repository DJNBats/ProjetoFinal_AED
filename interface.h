#ifndef INTERFACE_H_INCLUDED
#define INTERFACE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

typedef int Item;
// Estrutura de um no na lista de adjacencia
typedef struct lista {
    Item item;               // Armazena o destino da aresta
    struct Node* next;      // Ponteiro para o proximo no da lista
} lista;
typedef struct lista *_list;

// Estrutura do grafo
typedef struct {
    int vertices;           // Numero total de vertices
    _list* listaAdj;        // Vetor de ponteiros para as listas de adjacencia
} Grafo;

// Estruturas de fila para a BFS
typedef struct _element
{
    Item item;
    struct _element * next;
} element;

struct fila
{
    element * primeiro;
    element * ultimo;
};
typedef struct fila F;
//Funcoes da Fila
element *FilaNew(Item vItem, element *pNext);

void FilaDump(F*);

F *FilaInit(int);

int FilaEmpty(F* _fila);

void FilaPut(F*, Item);

Item FilaGet(F*);

#endif // INTERFACE_H_INCLUDED

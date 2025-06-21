#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
typedef int Item;
// Estrutura de fila para a aplicar o BFS
typedef struct _element
{
    Item item;
    struct _element *next;
} element;

struct fila
{
    element *primeiro;
    element *ultimo;
};
typedef struct fila F;

element *FilaNew(Item vItem, element *pNext);

void FilaDump(F *);

F *FilaInit(int);

int FilaEmpty(F *_fila);

void FilaPut(F *, Item);

Item FilaGet(F *);


#endif // FILA_H_INCLUDED

#include "interface.h"

// Fun��o para criar um novo n� com destino 'dest'
lista *novoNo(Item item)
{
    lista *novo = (lista *)malloc(sizeof(lista)); // Aloca mem�ria para o novo n�
    novo->item = item;                            // Define o destino da aresta
    novo->next = NULL;                            // Inicializa o pr�ximo como NULL
    return novo;                                  // Retorna o novo n�
}

// Fun��o para criar o grafo com 'vertices' v�rtices
Grafo *criarGrafo(int vertices)
{
    Grafo *grafo = (Grafo *)malloc(sizeof(Grafo)); // Aloca mem�ria para o grafo
    grafo->vertices = vertices;                    // Define o n�mero de v�rtices

    grafo->listaAdj = (_list *)malloc(vertices * sizeof(_list)); // Aloca vetor de listas
    for (int i = 0; i < vertices; i++)
        grafo->listaAdj[i] = NULL; // Inicializa cada lista como vazia

    return grafo; // Retorna o grafo criado
}

// Fun��o que adiciona uma aresta de 'origem' para 'destino'
void adicionarAresta(Grafo *grafo, int origem, int destino)
{
    lista *no = novoNo(destino);        // Cria o n� de destino
    no->next = grafo->listaAdj[origem]; // Insere no in�cio da lista de origem
    grafo->listaAdj[origem] = no;       // Atualiza a cabe�a da lista
}

element *FilaNew(Item vItem, element *pNext)
{
    element *x = (element *)malloc(sizeof(element));
    x->item = vItem;
    x->next = pNext;
    return x;
}
// Fun��o que cria uma fila com o tamanho indicado
F *FilaInit(int maxN)
{
    F *pFila = (F *)malloc(sizeof(F));
    pFila->primeiro = pFila->ultimo = NULL;
    return pFila;
}

// Verifica se a fila est� vazia
int FilaEmpty(F *_fila)
{
    return _fila->primeiro == NULL; // Retorna verdadeiro se frente for NULL
}

// Insere um valor no fim da fila
void FilaPut(F *pFila, Item vI)
{
    if (pFila->primeiro == NULL)
    { // a fila esta vazia

        pFila->ultimo = FilaNew(vI, pFila->primeiro);
        pFila->primeiro = pFila->ultimo;

        return;
    }
    // o item e colocado no fim da lista
    pFila->ultimo->next = FilaNew(vI, NULL);
    pFila->ultimo = pFila->ultimo->next;
}

// Remove e retorna o valor do in�cio da fila
Item FilaGet(F *pFila)
{
    Item item = pFila->primeiro->item;
    element *elem = pFila->primeiro->next;
    free(pFila->primeiro);
    pFila->primeiro = elem;
    return item;
}

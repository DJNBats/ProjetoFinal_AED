#include "fila.h"      // Inclui o ficheiro de cabecalho com a definicao da estrutura da fila
#include "interface.h" // Inclui funcionalidades de interface, se usadas em conjunto

// Funcao que cria um novo elemento da fila (no da lista ligada)
element *FilaNew(Item vItem, element *pNext)
{
    element *x = (element *)malloc(sizeof(element)); // Aloca memoria para um novo no
    x->item = vItem;        // Atribui o valor ao campo 'item' do no
    x->next = pNext;        // Define o ponteiro para o proximo no
    return x;               // Retorna o novo no criado
}

// Funcao que inicializa uma fila vazia
F *FilaInit(int maxN)
{
    F *pFila = (F *)malloc(sizeof(F)); // Aloca memoria para a estrutura da fila
    pFila->primeiro = pFila->ultimo = NULL; // Inicializa os ponteiros de inicio e fim como NULL
    return pFila;                          // Retorna o ponteiro para a nova fila
}

// Funcao que verifica se a fila esta vazia
int FilaEmpty(F *_fila)
{
    return _fila->primeiro == NULL; // Retorna 1 (verdadeiro) se a fila estiver vazia
}

// Funcao que insere um novo item no final da fila
void FilaPut(F *pFila, Item vI)
{
    if (pFila->primeiro == NULL)
    { // Caso a fila esteja vazia
        // Cria o primeiro e o ultimo no apontando para o mesmo elemento
        pFila->ultimo = FilaNew(vI, pFila->primeiro); // Cria novo no com o item e o ponteiro NULL
        pFila->primeiro = pFila->ultimo;              // Ambos os ponteiros apontam para o unico no
        return; // Retorna pois a insercao foi concluida
    }

    // Se ja existirem elementos, insere no final da lista
    pFila->ultimo->next = FilaNew(vI, NULL);   // Liga o novo no ao ultimo da fila
    pFila->ultimo = pFila->ultimo->next;       // Atualiza o ponteiro 'ultimo'
}

// Funcao que remove e retorna o item do in�cio da fila
Item FilaGet(F *pFila)
{
    Item item = pFila->primeiro->item;         // Guarda o valor do primeiro item da fila
    element *e = pFila->primeiro->next;     // Guarda o ponteiro para o segundo no
    free(pFila->primeiro);                     // Liberta a memoria do primeiro no
    pFila->primeiro = e;                    // Atualiza o ponteiro 'primeiro' da fila
    return item;                               // Retorna o item removido
}

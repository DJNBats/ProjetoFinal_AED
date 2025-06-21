#include "fila.h"      // Inclui o ficheiro de cabeçalho com a definição da estrutura da fila
#include "interface.h" // (Opcional) Inclui funcionalidades de interface, se usadas em conjunto

// Função que cria um novo elemento da fila (nó da lista ligada)
element *FilaNew(Item vItem, element *pNext)
{
    element *x = (element *)malloc(sizeof(element)); // Aloca memória para um novo nó
    x->item = vItem;        // Atribui o valor ao campo 'item' do nó
    x->next = pNext;        // Define o ponteiro para o próximo nó
    return x;               // Retorna o novo nó criado
}

// Função que inicializa uma fila vazia
F *FilaInit(int maxN)
{
    F *pFila = (F *)malloc(sizeof(F)); // Aloca memória para a estrutura da fila
    pFila->primeiro = pFila->ultimo = NULL; // Inicializa os ponteiros de início e fim como NULL
    return pFila;                          // Retorna o ponteiro para a nova fila
}

// Função que verifica se a fila está vazia
int FilaEmpty(F *_fila)
{
    return _fila->primeiro == NULL; // Retorna 1 (verdadeiro) se a fila estiver vazia
}

// Função que insere um novo item no final da fila
void FilaPut(F *pFila, Item vI)
{
    if (pFila->primeiro == NULL)
    { // Caso a fila esteja vazia
        // Cria o primeiro e o último nó apontando para o mesmo elemento
        pFila->ultimo = FilaNew(vI, pFila->primeiro); // Cria novo nó com o item e o ponteiro NULL
        pFila->primeiro = pFila->ultimo;              // Ambos os ponteiros apontam para o único nó
        return; // Retorna pois a inserção foi concluída
    }

    // Se já existirem elementos, insere no final da lista
    pFila->ultimo->next = FilaNew(vI, NULL);   // Liga o novo nó ao último da fila
    pFila->ultimo = pFila->ultimo->next;       // Atualiza o ponteiro 'último'
}

// Função que remove e retorna o item do início da fila
Item FilaGet(F *pFila)
{
    Item item = pFila->primeiro->item;         // Guarda o valor do primeiro item da fila
    element *e = pFila->primeiro->next;     // Guarda o ponteiro para o segundo nó
    free(pFila->primeiro);                     // Liberta a memória do primeiro nó
    pFila->primeiro = e;                    // Atualiza o ponteiro 'primeiro' da fila
    return item;                               // Retorna o item removido
}

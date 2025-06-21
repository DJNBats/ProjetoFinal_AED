#include "fila.h"      // Inclui o ficheiro de cabe�alho com a defini��o da estrutura da fila
#include "interface.h" // (Opcional) Inclui funcionalidades de interface, se usadas em conjunto

// Fun��o que cria um novo elemento da fila (n� da lista ligada)
element *FilaNew(Item vItem, element *pNext)
{
    element *x = (element *)malloc(sizeof(element)); // Aloca mem�ria para um novo n�
    x->item = vItem;        // Atribui o valor ao campo 'item' do n�
    x->next = pNext;        // Define o ponteiro para o pr�ximo n�
    return x;               // Retorna o novo n� criado
}

// Fun��o que inicializa uma fila vazia
F *FilaInit(int maxN)
{
    F *pFila = (F *)malloc(sizeof(F)); // Aloca mem�ria para a estrutura da fila
    pFila->primeiro = pFila->ultimo = NULL; // Inicializa os ponteiros de in�cio e fim como NULL
    return pFila;                          // Retorna o ponteiro para a nova fila
}

// Fun��o que verifica se a fila est� vazia
int FilaEmpty(F *_fila)
{
    return _fila->primeiro == NULL; // Retorna 1 (verdadeiro) se a fila estiver vazia
}

// Fun��o que insere um novo item no final da fila
void FilaPut(F *pFila, Item vI)
{
    if (pFila->primeiro == NULL)
    { // Caso a fila esteja vazia
        // Cria o primeiro e o �ltimo n� apontando para o mesmo elemento
        pFila->ultimo = FilaNew(vI, pFila->primeiro); // Cria novo n� com o item e o ponteiro NULL
        pFila->primeiro = pFila->ultimo;              // Ambos os ponteiros apontam para o �nico n�
        return; // Retorna pois a inser��o foi conclu�da
    }

    // Se j� existirem elementos, insere no final da lista
    pFila->ultimo->next = FilaNew(vI, NULL);   // Liga o novo n� ao �ltimo da fila
    pFila->ultimo = pFila->ultimo->next;       // Atualiza o ponteiro '�ltimo'
}

// Fun��o que remove e retorna o item do in�cio da fila
Item FilaGet(F *pFila)
{
    Item item = pFila->primeiro->item;         // Guarda o valor do primeiro item da fila
    element *e = pFila->primeiro->next;     // Guarda o ponteiro para o segundo n�
    free(pFila->primeiro);                     // Liberta a mem�ria do primeiro n�
    pFila->primeiro = e;                    // Atualiza o ponteiro 'primeiro' da fila
    return item;                               // Retorna o item removido
}

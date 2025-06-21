#include "fila.h"
#include "interface.h"

// Funcao para criar um novo
lista *novoNo(Item item)
{
    lista *novo = (lista *)malloc(sizeof(lista)); // Aloca memoria para o novo no
    novo->item = item;                            // Define o destino da aresta
    novo->next = NULL;                            // Inicializa o proximo como NULL
    return novo;                                  // Retorna o novo no
}

// Funcao para criar o grafo com 'vertices' vertices
Grafo *criarGrafo(int vertices)
{
    Grafo *grafo = (Grafo *)malloc(sizeof(Grafo)); // Aloca memoria para o grafo
    grafo->vertices = vertices;                    // Define o numero de vertices

    grafo->listaAdj = (_list *)malloc(vertices * sizeof(_list)); // Aloca vetor de listas
    for (int i = 0; i < vertices; i++)
        grafo->listaAdj[i] = NULL; // Inicializa cada lista como vazia

    return grafo; // Retorna o grafo criado
}

// Funcao que adiciona uma aresta de 'origem' para 'destino'
void adicionarAresta(Grafo *grafo, int origem, int destino)
{
    lista *no = novoNo(destino);        // Cria o no de destino
    no->next = grafo->listaAdj[origem]; // Insere no inicio da lista de origem
    grafo->listaAdj[origem] = no;       // Atualiza a cabec a da lista
}


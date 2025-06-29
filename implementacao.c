#include "fila.h"
#include "interface.h"

// Funcao para criar um novo
lista *novoNo(Item item)
{
    lista *novo = (lista *)malloc(sizeof(lista)); // Aloca memoria para o novo no
    novo->item = item;                            // Define o destino da aresta
    novo->next = NULL;                            // Inicializa o proximo como NULL
    return novo;                                  // Retorna o novo n�
}

// Funcao para criar o grafo com 'vertices' vertices
Grafo *criarGrafo(int vertices)
{
    Grafo *grafo = (Grafo *)malloc(sizeof(Grafo)); // Aloca memoria para o grafo
    grafo->vertices = vertices;                    // Define o numero de vertices

    grafo->listaAdj = (lista **)malloc(vertices * sizeof(lista*)); // Aloca vetor de listas
    for (int i = 0; i < vertices; i++)
        grafo->listaAdj[i] = NULL; // Inicializa cada lista como vazia

    return grafo; // Retorna o grafo criado
}

// Funcao que adiciona uma aresta de 'origem' para 'destino'
void adicionarAresta(Grafo *grafo, int origem, int destino, int dirigido)
{
    lista *no = novoNo(destino);        // Cria o no de destino
    no->next = grafo->listaAdj[origem]; // Insere no inicio da lista de origem
    grafo->listaAdj[origem] = no;       // Atualiza a cabec a da lista

        // Se o grafo for não-direcionado, adiciona a aresta inversa
    if (!dirigido)
    {
        lista *noInverso = novoNo(origem);
        noInverso->next = grafo->listaAdj[destino];
        grafo->listaAdj[destino] = noInverso;
    }
}
/*Implementacao do Livro Estruturas de dados usando C pag. 741
void BFS(Grafo *grafo, int vertice){
while (s != NULL)
{
    visit(s);
    FilaPut(ndqueue,s);
    while (FilaEmpty(ndqueue) == FALSE)
    {
        x = FilaGet(ndqueue);
        // visita todos os sucessores de x
        firstsucc(x,yptr,nd);
        while (nd != NULL)
        {
            if (visited(nd) == FALSE)
            {
                visit(nd);
                FilaPut(ndqueue,nd);
            } // fim if
            nextsucc(x,yptr,nd);
        } // fim while
    } // fim while
    s = select();
} //7 fim while
}*/

//static int num[50];
/* A função GRAPHbfs() implementa o algoritmo de busca em largura.
Ela visita todos os vértices do grafo G que estão ao alcance do vértice s e registra num vetor num[] a ordem em que os vértices são descobertos.
Esta versão da função supõe que o grafo G é representado por listas de adjacência.  (Código inspirado no programa 18.9 de Sedgewick.)
void GRAPHbfs( Grafo* G, int s)
{
    int cnt = 0;
    for (int v = 0; v < G->V; ++v)
        num[v] = -1;
    FilaInit( G->vertices);
    num[s] = cnt++;
    FilaPut(s);

    while (!FilaEmpty( ))
    {
        int v = FilaGet( );
        for (link a = G->adj[v]; a != NULL; a = a->next)
            if (num[a->w] == -1)
            {
                num[a->w] = cnt++;
                FilaPut( a->w);
            }
    }
    FilaDump( );
}*/

void BFS(Grafo *grafo, int inicio)
       {
           int *visitado = (int *)calloc(grafo->vertices, sizeof(int));     // Vetor para marcar vértices visitados
           int *predecessor = (int *)malloc(grafo->vertices * sizeof(int)); // Vetor de predecessores
           for (int i = 0; i < grafo->vertices; i++)
               predecessor[i] = -1; // Inicializa todos os predecessores como -1

           F *fila = FilaInit(grafo->vertices); // Cria a fila
           visitado[inicio] = 1;                    // Marca o vértice inicial como visitado
           FilaPut(fila, inicio);                // Enfileira o vértice inicial

           printf("Ordem de visita: "); // Imprime a ordem de visita

           while (!FilaEmpty(fila))
           {
               int v = FilaGet(fila); // Remove o próximo vértice da fila
               printf("%d ", v);            // Imprime o vértice visitado

               lista *temp = grafo->listaAdj[v]; // Acessa a lista de adjacência do vértice
               while (temp)
               { // Percorre os vizinhos
                   int adj = temp->item;
                   if (!visitado[adj])
                   {                          // Se ainda não foi visitado
                       visitado[adj] = 1;     // Marca como visitado
                       predecessor[adj] = v;  // Define o predecessor
                       FilaPut(fila, adj); // Enfileira o vizinho
                   }
                   temp = temp->next; // Vai para o próximo vizinho
               }
           }

           printf("\n\nArvore Breadth First (BF):\n");
           printf("Vertice\tPredecessor\n");
           for (int i = 0; i < grafo->vertices; i++)
           {
               if (i == inicio)
                   printf("%d\t(Raiz)\n", i); // O vértice inicial é a raiz
               else
                   printf("%d\t%d\n", i, predecessor[i]); // Imprime o predecessor
           }

           free(visitado); // Liberta a memória dos vetores
           free(predecessor);
            // Liberta todos os nós da fila antes de libertar a estrutura
            while (!FilaEmpty(fila)) {
                FilaGet(fila); // remove e já libera a memória
            }
            free(fila);

}

#include "fila.h"        // Inclui definições relacionadas à fila
#include "interface.h"   // Inclui definições da interface gráfica ou funções auxiliares do grafo

int main()
{
    int v, a, origem, destino;  // Declara as variáveis para vértices, arestas, origem e destino

    /*adicionarAresta(g, 0, 1, 0); // Grafo não-direcionado
    adicionarAresta(g, 0, 2, 0);
    adicionarAresta(g, 1, 3, 0);
    adicionarAresta(g, 3, 4, 0);

    BFS(g, 0); // Faz busca em largura a partir do vértice 0*/

    printf("Introduza a ordem do digrafo (numero de vertices): ");
    scanf("%d", &v); // Lê o número total de vértices do grafo (ordem)

    printf("\nIntroduza a dimensao do digrafo (numero de arestas): ");
    scanf("%d", &a); // Lê o número total de arestas do grafo (dimensão)

    Grafo *grafo = criarGrafo(v); // Cria dinamicamente o grafo com 'v' vértices

    // Loop para ler as 'a' arestas, uma de cada vez
    for (int i = 0; i < a; i++)
    {
        printf("\n\tAresta %d\n", i + 1);        // Indica o número da aresta atual
        printf("\nOrigem: ");
        scanf("\n%d", &origem);                // Lê o vértice de origem da aresta
        printf("\nDestino: ");
        scanf("\n%d", &destino);               // Lê o vértice de destino da aresta
        adicionarAresta(grafo, origem, destino,0); // Adiciona a aresta ao grafo (grafo direcionado)
    }

    // Imprime a representação do grafo como lista de adjacência
    printf("\nLista de Adjacencia:\n");
    for (int i = 0; i < v; i++)                // Percorre todos os vértices
    {
        printf("\n%d:", i);                    // Imprime o número do vértice
        lista *temp = grafo->listaAdj[i];      // Ponteiro temporário para percorrer a lista de adjacência
        while (temp)                           // Percorre a lista ligada de vizinhos
        {
            printf(" %d", temp->item);         // Imprime o vértice adjacente
            temp = temp->next;                 // Vai para o próximo vizinho
        }
        printf("\n");                          // Nova linha após cada lista de adjacência
    }


    int inicio;
    printf("\nVertice de arranque para BFS: ");
    scanf("%d", &inicio); // Lê o vértice inicial para BFS

    printf("\nTravessia em largura Breadth First Search\n");
    BFS(grafo, inicio); // Executa BFS

    return 0; // Termina o programa com sucesso
}

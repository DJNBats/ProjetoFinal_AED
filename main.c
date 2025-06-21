#include "fila.h"        // Inclui definições relacionadas à fila (provavelmente usada por outras funções do programa)
#include "interface.h"   // Inclui definições da interface gráfica ou funções auxiliares do grafo

int main()
{
    int v, a, origem, destino;  // Declara as variáveis para vértices, arestas, origem e destino

    printf("Introduza a ordem do digrafo (numero de vertices): ");
    scanf("%d", &v); // Lê o número total de vértices do grafo (ordem)

    printf("\nIntroduza a dimensão do dígrafo (número de arestas): ");
    scanf("%d", &a); // Lê o número total de arestas do grafo (dimensão)

    Grafo *grafo = criarGrafo(v); // Cria dinamicamente o grafo com 'v' vértices

    // Loop para ler as 'a' arestas, uma de cada vez
    for (int i = 0; i < a; i++)
    {
        printf("\nAresta %d\n", i + 1);        // Indica o número da aresta atual
        printf("\nOrigem: ");
        scanf("\n%d", &origem);                // Lê o vértice de origem da aresta
        printf("\nDestino: ");
        scanf("\n%d", &destino);               // Lê o vértice de destino da aresta
        adicionarAresta(grafo, origem, destino); // Adiciona a aresta ao grafo (grafo direcionado)
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

    return 0; // Termina o programa com sucesso
}

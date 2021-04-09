#include <stdio.h>
#include <stdlib.h>
#define MAX 10 //Tamanho do grafo
#define INF 999 //Infinito

void dijkstra();

int main()
{
    int G[MAX][MAX];
    int nvertices, inicio, fim, i, j;

    printf("Numero de vertices:\n");
    scanf("%d", &nvertices);

    printf("Entre o grafo:\n");

    for (i = 0; i < nvertices; i++)
    {
        for (j = 0; j < nvertices; j++)
        {
            scanf("%d", &G[i][j]);
        }
        
    }

    printf("Digite o nodo inicial:\n");
    scanf("%d", &inicio);
    printf("Digite o nodo final:\n");
    scanf("%d", &fim);


    dijkstra(G, nvertices, inicio, fim);

    return 0;
    
}

void dijkstra(int G[MAX][MAX], int nvertices, int inicio, int fim)
{
    int custo[MAX][MAX], dist[MAX], visitado[MAX], ant[MAX];
    int i, j, mindist, proxnodo;

    for (i = 0; i < nvertices; i++) //Coloca o valor do caminho dos verticies adjacentes, caso não seja adjacente coloca infinito no caminho
    {
        for (j = 0; j < nvertices; j++)
        {
            if(G[i][j] == 0) //Senão for um nodo adjacente, caminho infinito
            {
                custo[i][j] = INF;
            }
            else //Verticie adjacente, recebe o valor do caminho
            {
                custo[i][j] = G[i][j];
            }
        }
        
    }

    for (i = 0; i < nvertices; i++)//inicia os  vetores
    {
        dist[i] = custo[inicio][i];
        ant[i] = inicio;
        visitado[i] = 0;
    }
    
    dist[inicio] = 0;//distancia do nodo inicial a ele mesmo é 0
    visitado[inicio] = 1;//nodo inicial marcado como visitado
    int count = 1;

    while (count < nvertices-1)
    {
        mindist = INF;
        for (i = 0; i < nvertices; i++)//proxnodo da uma distancia minima do nodo
        {
            if (dist[i] < mindist && !visitado[i])
            {
                mindist = dist[i]; 
                proxnodo = i; 
            }
            
        }

        visitado[proxnodo] = 1; //marca o nodo como visitado

        for (i = 0; i < nvertices; i++)//checa se a um caminho melhor pelo proxnodo
        {
            if (!visitado[i])
            {
                if((mindist + custo[proxnodo][i]) < dist[i])
                {
                    dist[i] = mindist + custo[proxnodo][i]; //armazena a menor distancia em relação ao nodo inicial
                    ant[i] = proxnodo;//armazena qual é o nodo anterior antes de chegar em algum nodo
                }
            }
            
        }
        count++;
        
    }

    for (i = 0; i < nvertices; i++)
    {
        if (i == fim)//printa a distancia entre o nodo inicial e o nodo final
        {
            printf("A distancia do nodo %d do nodo %d eh %d\n", inicio, i, dist[i]);
            printf("O caminho entre os nodos eh: %d", i);

            j = i;
            do
            {
                j = ant[j];
                printf("<-%d", j);
            } while (j != inicio);
            
        }
        printf("\n");
    }
    
    

    






}
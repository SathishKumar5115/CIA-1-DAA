#include <stdio.h>
#include <stdlib.h>

#define INF 99999
#define false 0
#define true 1

int n; 
int graph[100][100];

int minKey(int key[], int mstSet[]) {
    int min = INF, min_index;
    for (int v = 0; v < n; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;
    return min_index;
}


void primMST() {
    int parent[n]; 
    int key[n]; 
    int mstSet[n]; 

    for (int i = 0; i < n; i++)
        key[i] = INF, mstSet[i] = false;

    key[0] = 0;
    parent[0] = -1; 

    for (int count = 0; count < n - 1; count++) {
        int u = minKey(key, mstSet);
        mstSet[u] = true;

       
        for (int v = 0; v < n; v++)
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }

    printf("Edge \tWeight\n");
    for (int i = 1; i < n; i++)
        printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
}

int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    primMST();

    return 0;
}

//Prims algo is greedy algo it asssusmes that edges of graph can be traversed in both directions but in directed graph it is specific direction.
//every other node is not traversable from another in directed graph

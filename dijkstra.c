#include <stdio.h>
#include <limits.h>

#define MAX_NODES 100
#define INF INT_MAX

void dijkstra(int start, int end, int graph[MAX_NODES][MAX_NODES], int num_nodes) {
    int distances[MAX_NODES];
    int visited[MAX_NODES];


    for (int i = 0; i < num_nodes; i++) {
        distances[i] = INF;
        visited[i] = 0;
    }

    distances[start] = 0;

    for (int i = 0; i < num_nodes - 1; i++) {
      
        int min_distance = INF, next_node;
        for (int j = 0; j < num_nodes; j++) {
            if (!visited[j] && distances[j] < min_distance) {
                min_distance = distances[j];
                next_node = j;
            }
        }
        visited[next_node] = 1;
        for (int j = 0; j < num_nodes; j++) {
            if (!visited[j] && graph[next_node][j] && distances[next_node] + graph[next_node][j] < distances[j]) {
                distances[j] = distances[next_node] + graph[next_node][j];
            }
        }
    }


    printf("Shortest distance from node %d to node %d: %d\n", start, end, distances[end]);
}

int main() {
  
    Graph[0][0] = 0;
    Graph[0][1] = 0;
    Graph[0][2] = 2;
    Graph[0][3] = 0;
    Graph[0][4] = 0;
    Graph[0][5] = 0;

    Graph[1][0] = 1;
    Graph[1][1] = 0;
    Graph[1][2] = 0;
    Graph[1][3] = 0;
    Graph[1][4] = 0;
    Graph[1][5] = 0;
  
    Graph[2][0] = 0;
    Graph[2][1] = -2;
    Graph[2][2] = 0;
    Graph[2][3] = 0;
    Graph[2][4] = 0;
    Graph[2][5] = 0;
  
    Graph[3][0] = -4;
    Graph[3][1] = 0;
    Graph[3][2] = -1;
    Graph[3][3] = 0;
    Graph[3][4] = 0;
    Graph[3][5] = 0;

    Graph[4][0] = 0;
    Graph[4][1] = 0;
    Graph[4][2] = 0;
    Graph[4][3] = 1;
    Graph[4][4] = 0;
    Graph[4][5] = 0;
  
    Graph[5][0] = 10;
    Graph[5][1] = 0;
    Graph[5][2] = 0;
    Graph[5][3] = 0;
    Graph[5][4] = 8;
    Graph[5][5] = 0;
    };

    int num_nodes = 6;
    int start = 0;
    int end = 5;

    dijkstra(start, end, graph, num_nodes);

    return 0;
}


#include <stdio.h>
#define MAX 100

int graph[MAX][MAX];
int visited[MAX];
int numVertices;

// DFS
void DFS(int vertex) {
    visited[vertex] = 1;
    printf("%d ", vertex);

    for (int i = 0; i < numVertices; i++) {
        if (graph[vertex][i] && !visited[i]) {
            DFS(i);
        }
    }
}

int main() {
    numVertices = 4;

    // Adjacency matrix
    // 0->1, 0->2, 1->2, 2->0, 2->3, 3->3
    for (int i = 0; i < numVertices; i++)
        for (int j = 0; j < numVertices; j++)
            graph[i][j] = 0;

    graph[0][1] = 1;
    graph[0][2] = 1;
    graph[1][2] = 1;
    graph[2][0] = 1;
    graph[2][3] = 1;
    graph[3][3] = 1;

    // DFS başlat
    printf("DFS starting from vertex 2:\n");
    for (int i = 0; i < numVertices; i++) visited[i] = 0;
    DFS(2);
    printf("\n");

    return 0;
}

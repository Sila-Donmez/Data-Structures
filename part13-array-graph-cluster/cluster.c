#include <stdio.h>

#define MAX 10

int graph[MAX][MAX];
int visited[MAX];
int n = 5;

void DFS(int v) {
    visited[v] = 1;
    printf("%d ", v);

    for (int i = 0; i < n; i++) {
        if (graph[v][i] && !visited[i]) {
            DFS(i);
        }
    }
}

int main() {
    // graph initialization (2 cluster)
    // Cluster 1: 0-1-2
    graph[0][1] = graph[1][0] = 1;
    graph[1][2] = graph[2][1] = 1;

    // Cluster 2: 3-4
    graph[3][4] = graph[4][3] = 1;

    int clusterCount = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            printf("Cluster %d: ", clusterCount + 1);
            DFS(i);
            printf("\n");
            clusterCount++;
        }
    }

    printf("Toplam cluster sayisi: %d\n", clusterCount);
    return 0;
}

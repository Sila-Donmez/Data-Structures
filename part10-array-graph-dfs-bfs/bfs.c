#include <stdio.h>
#define MAX 100

int graph[MAX][MAX];
int visited[MAX];
int queue[MAX];
int front = 0, rear = 0;
int numVertices;

// BFS
void BFS(int startVertex) {
    for (int i = 0; i < numVertices; i++)
        visited[i] = 0;

    visited[startVertex] = 1;
    queue[rear++] = startVertex;

    while (front < rear) {
        int current = queue[front++];
        printf("%d ", current);

        for (int i = 0; i < numVertices; i++) {
            if (graph[current][i] && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
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

    printf("BFS starting from vertex 2:\n");
    BFS(2);
    printf("\n");

    return 0;
}

#include <stdio.h>

#define MAX 100

// Array ile tree print (level order)
void printTree(char tree[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%c ", tree[i]);
    }
    printf("\n");
}

int main() {
    // Örnek ağaç: A,B,C,D,E
    char tree[MAX] = {'A', 'B', 'C', 'D', 'E'};
    int size = 5;

    printf("Array-based tree (level order):\n");
    printTree(tree, size);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void destroy(Node* head) {
    if (head == NULL)
        return;

    destroy(head->next);
    free(head);
}

int main() {
    Node* n1 = malloc(sizeof(Node));
    Node* n2 = malloc(sizeof(Node));

    n1->data = 1;
    n1->next = n2;

    n2->data = 2;
    n2->next = NULL;

    destroy(n1);
    return 0;
}

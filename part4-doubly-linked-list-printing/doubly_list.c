#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

// Yeni düğüm oluşturma
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Listenin sonuna ekleme
void append(Node** head, int data) {
    Node* newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

// Non-recursive yazdırma
void printListIterative(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Recursive yazdırma
void printListRecursive(Node* head) {
    if (head == NULL)
        return;

    printf("%d ", head->data);
    printListRecursive(head->next);
}

// Belleği temizleme
void destroy(Node* head) {
    if (head == NULL)
        return;

    destroy(head->next);
    free(head);
}

int main() {
    Node* head = NULL;

    append(&head, 10);
    append(&head, 20);
    append(&head, 30);

    printf("Non-recursive yazdirma: ");
    printListIterative(head);

    printf("Recursive yazdirma: ");
    printListRecursive(head);
    printf("\n");

    destroy(head);
    return 0;
}

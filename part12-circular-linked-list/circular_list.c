#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Yeni düğüm oluştur
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = newNode; // circular
    return newNode;
}

// Sona ekleme
void append(Node** head, int data) {
    Node* newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Node* temp = *head;
    while (temp->next != *head)
        temp = temp->next;

    temp->next = newNode;
    newNode->next = *head;
}

// Traversal
void traverse(Node* head) {
    if (head == NULL)
        return;

    Node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("\n");
}

// Değerine göre silme
void deleteNode(Node** head, int key) {
    if (*head == NULL)
        return;

    Node* curr = *head;
    Node* prev = NULL;

    // Tek eleman varsa
    if (curr->data == key && curr->next == *head) {
        free(curr);
        *head = NULL;
        return;
    }

    // Head silinecekse
    if (curr->data == key) {
        while (curr->next != *head)
            curr = curr->next;

        curr->next = (*head)->next;
        free(*head);
        *head = curr->next;
        return;
    }

    prev = *head;
    curr = prev->next;

    while (curr != *head) {
        if (curr->data == key) {
            prev->next = curr->next;
            free(curr);
            return;
        }
        prev = curr;
        curr = curr->next;
    }

    printf("Eleman bulunamadi.\n");
}

int main() {
    Node* head = NULL;

    append(&head, 10);
    append(&head, 20);
    append(&head, 30);

    printf("Liste: ");
    traverse(head);

    deleteNode(&head, 20);
    printf("20 silindikten sonra: ");
    traverse(head);

    return 0;
}

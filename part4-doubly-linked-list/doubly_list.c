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

// Belirli bir elemandan sonra araya ekleme
void insertAfter(Node* head, int prevData, int newData) {
    Node* temp = head;

    while (temp != NULL && temp->data != prevData)
        temp = temp->next;

    if (temp == NULL) {
        printf("Eleman bulunamadi.\n");
        return;
    }

    Node* newNode = createNode(newData);
    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = newNode;

    temp->next = newNode;
}

// Değerine göre silme
void deleteNode(Node** head, int key) {
    Node* temp = *head;

    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL) {
        printf("Silinecek eleman bulunamadi.\n");
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        *head = temp->next; // ilk eleman siliniyorsa

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
}

// Non-recursive traversal
void printListIterative(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Recursive traversal
void printListRecursive(Node* head) {
    if (head == NULL)
        return;

    printf("%d ", head->data);
    printListRecursive(head->next);
}

// Belleği recursive temizleme
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

    printf("Ilk liste: ");
    printListIterative(head);

    insertAfter(head, 20, 25);
    printf("20'den sonra 25 eklendi: ");
    printListIterative(head);

    deleteNode(&head, 10);
    printf("10 silindikten sonra: ");
    printListIterative(head);

    printf("Recursive yazdirma: ");
    printListRecursive(head);
    printf("\n");

    destroy(head);
    return 0;
}

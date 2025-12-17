// Array tabanlı queue işlemleri: enqueue, dequeue, peek
#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

// Kuyruğun boş olup olmadığını kontrol
int isEmpty() {
    return front == -1;
}

// Kuyruğun dolu olup olmadığını kontrol
int isFull() {
    return rear == MAX - 1;
}

// Enqueue: eleman ekleme
void enqueue(int x) {
    if (isFull()) {
        printf("Queue dolu!\n");
        return;
    }
    if (isEmpty()) front = 0;
    queue[++rear] = x;
    printf("%d enqueue edildi.\n", x);
}

// Dequeue: eleman çıkarma
int dequeue() {
    if (isEmpty()) {
        printf("Queue boş!\n");
        return -1;
    }
    int val = queue[front];
    if (front == rear) { // Tek eleman kaldıysa
        front = rear = -1;
    } else {
        front++;
    }
    return val;
}

// Peek: ön taraftaki elemanı gör
int peek() {
    if (isEmpty()) {
        printf("Queue boş!\n");
        return -1;
    }
    return queue[front];
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);

    printf("Ön eleman: %d\n", peek());

    printf("Dequeued: %d\n", dequeue());
    printf("Dequeued: %d\n", dequeue());

    printf("Ön eleman şimdi: %d\n", peek());

    enqueue(40);
    enqueue(50);
    enqueue(60); // Doluluk testi

    return 0;
}

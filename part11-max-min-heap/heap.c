#include <stdio.h>
#define MAX 100

int heap[MAX];
int size = 0;

// Swap
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Max Heap Insert
void insertMaxHeap(int value) {
    heap[size] = value;
    int i = size;
    size++;

    while (i != 0 && heap[(i - 1)/2] < heap[i]) {
        swap(&heap[i], &heap[(i - 1)/2]);
        i = (i - 1)/2;
    }
}

// Max Heap Remove (root)
int removeMaxHeap() {
    if (size <= 0) return -1;
    int root = heap[0];
    heap[0] = heap[size - 1];
    size--;

    int i = 0;
    while (i*2+1 < size) {
        int largest = i;
        int left = i*2+1;
        int right = i*2+2;

        if (left < size && heap[left] > heap[largest]) largest = left;
        if (right < size && heap[right] > heap[largest]) largest = right;

        if (largest != i) {
            swap(&heap[i], &heap[largest]);
            i = largest;
        } else break;
    }
    return root;
}

// Print Heap
void printHeap() {
    for (int i = 0; i < size; i++) printf("%d ", heap[i]);
    printf("\n");
}

int main() {
    insertMaxHeap(10);
    insertMaxHeap(15);
    insertMaxHeap(7);
    insertMaxHeap(12);
    insertMaxHeap(90);
    insertMaxHeap(2);

    printf("Max Heap:\n");
    printHeap();

    printf("Removed root: %d\n", removeMaxHeap());
    printf("Heap after removal:\n");
    printHeap();

    return 0;
}

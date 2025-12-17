#include <stdio.h>
#include <stdlib.h>

// AST düğümü
typedef struct Node {
    char value;           // operand veya operator
    struct Node* left;    // sol çocuk
    struct Node* right;   // sağ çocuk
} Node;

// Yeni düğüm oluştur
Node* createNode(char val, Node* left, Node* right) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->value = val;
    node->left = left;
    node->right = right;
    return node;
}

// AST’yi preorder (root-left-right) olarak yazdır
void printPreorder(Node* root) {
    if (!root) return;
    printf("%c ", root->value);
    printPreorder(root->left);
    printPreorder(root->right);
}

int main() {
    // Örnek ifade: a - (b + c * 2)
    Node* nodeC = createNode('c', NULL, NULL);
    Node* node2 = createNode('2', NULL, NULL);
    Node* nodeMul = createNode('*', nodeC, node2);

    Node* nodeB = createNode('b', NULL, NULL);
    Node* nodeAdd = createNode('+', nodeB, nodeMul);

    Node* nodeA = createNode('a', NULL, NULL);
    Node* nodeSub = createNode('-', nodeA, nodeAdd);

    printf("Preorder (prefix) traversal of AST for a - (b + c*2):\n");
    printPreorder(nodeSub);
    printf("\n");

    return 0;
}

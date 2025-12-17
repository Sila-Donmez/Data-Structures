#include <stdio.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    return stack[top--];
}

int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

void infixToPostfix(char infix[], char postfix[]) {
    int i, k = 0;
    char c;

    for (i = 0; infix[i] != '\0'; i++) {
        c = infix[i];

        // Operand
        if (isalnum(c)) {
            postfix[k++] = c;
        }
        // Sol parantez
        else if (c == '(') {
            push(c);
        }
        // Sağ parantez
        else if (c == ')') {
            while (stack[top] != '(')
                postfix[k++] = pop();
            pop(); // '(' çıkar
        }
        // Operatör
        else {
            while (top != -1 && precedence(stack[top]) >= precedence(c))
                postfix[k++] = pop();
            push(c);
        }
    }

    // Stack'te kalan operatörleri ekle
    while (top != -1)
        postfix[k++] = pop();

    postfix[k] = '\0';
}

int main() {
    char infix1[] = "A+B*C";
    char infix2[] = "(A+B)*C";
    char postfix[MAX];

    infixToPostfix(infix1, postfix);
    printf("Infix: %s -> Postfix: %s\n", infix1, postfix);

    infixToPostfix(infix2, postfix);
    printf("Infix: %s -> Postfix: %s\n", infix2, postfix);

    return 0;
}
/*
A + B * C     → A B C * +
(A + B) * C   → A B + C *
*/

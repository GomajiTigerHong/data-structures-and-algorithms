#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

struct Node {
    char data;
    struct Node * next;
};

struct Node * top = NULL;

void push(char x) {
    struct Node * temp;
    temp = (struct Node *)malloc(sizeof(struct Node));

    if (temp == NULL) {
        printf("stack is full\n");
    }
    else {
        temp->data = x;
        temp->next = top;
        top = temp;
    }
}

char pop() {
    struct Node * temp;
    char x = -1;

    if (top == NULL) {
        printf("stack if full\n");
    }
    else {
        temp = top;
        top = top->next;
        x = temp->data;
    }
    return x;
}

void display() {
    struct Node * temp;
    temp = top;
    while (temp) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

int isBalanced(char * exp) {
    for (int i; exp[i] != '\0'; i++) {
        if (exp[i] == '(') {
            push(exp[i]);
        }
        if (exp[i] == ')') {
            if (!top) {
                return 0;   
            }
            pop();
        }
    }
    if (!top) {
        return 1;
    }
    if (top) {
        return 0;
    }
}

int pre(char x) {
    if (x == '+' || x == '-') {
        return 1;
    }
    if (x == '*' || x == '/') {
        return 2;
    }
    return 0;
}

int isOperand(char x) {
    if (x == '+' || x == '-' || x == '*' || x == '/') {
        return 0;
    }
    return 1;
}

char * infixToPostfix(char * infix) {
    int i = 0;
    int j = 0;
    char * postfix;
    int len = strlen(infix);
    postfix = (char *)malloc((len + 2)*sizeof(char));
    while(infix[i] != '\0') {
        if (isOperand(infix[i])) {
            postfix[j++] = infix[i++];
        }
        if (!isOperand(infix[i])) {
            if (pre(infix[i]) > pre(top->data)) {
                push(infix[i++]);
            } else {
                postfix[j++] = pop();
            }
        }
    }
    while(top) {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
    return postfix;
}

int main() {
    char * infix = "a+b*c-d/e";
    push('#');
    char * postfix = infixToPostfix(infix);
    printf("%s\n", postfix);
    return 0;
}
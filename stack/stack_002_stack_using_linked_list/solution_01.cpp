#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node * next; 
};

struct Node * top = NULL;

void push(int x) {
    struct Node * temp;
    temp = (struct Node *)malloc(sizeof(struct Node));
    if (temp == NULL) {
        printf("stack if full\n");
    }
    else {
        temp->data = x;
        temp->next = top;
        top = temp;
    }
}

void display(){
    struct Node * pos;
    pos = top;
    while(pos) {
        printf("%d\n",pos->data);
        pos = pos->next;
    } 
}

int pop() {
    struct Node * temp;
    int x = -1;
    if (top == NULL) {
        printf("stack is empty\n");
    }
    else {
        temp = top;
        top = top->next;
        x = temp->data;
        free(temp);
    }
    return x;
}

int isBalanced(char *exp) {
    for (int i = 0 ; exp[i] != '\0' ; i++) {
        if (exp[i] == '(') {
            push(exp[i]);
        }
        if (exp[i] == ')') {
            if (top == NULL) {
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

int main() {
    char * exp = "((a+b)*(c-d))";
    printf("%d\n",isBalanced(exp));
    return 0;
}

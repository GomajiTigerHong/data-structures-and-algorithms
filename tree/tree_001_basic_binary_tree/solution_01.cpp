#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

struct Node * root = NULL;

void treeCreate() {
    struct Node * p;
    struct Node * temp;
    int x;
    struct Queue q;
    create(&q, 100);
    printf("enter root value\n");
    scanf("%d", &x);
    root = (struct Node *)malloc(sizeof(struct Node));
    root->data = x;
    root->lchild = root->rchild = NULL;
    enqueue(&q, root);

    while (!isEmpty(q)) {
        p = dequeue(&q);
        printf("enter left child of %d\n", p->data);
        scanf("%d", &x);
        if (x != -1) {
            temp = (struct Node *)malloc(sizeof(struct Node));
            temp->data = x;
            temp->lchild = temp->rchild = NULL;
            p->lchild = temp;
            enqueue(&q, temp);
        }
        printf("enter right child of %d\n", p->data);
        scanf("%d", &x);
        if (x != -1) {
            temp = (struct Node *)malloc(sizeof(struct Node));
            temp->data = x;
            temp->lchild = temp->rchild = NULL;
            p->rchild = temp;
            enqueue(&q, temp);
        }
    }
}

void preorder(struct Node * p) {
    if (p) {
        printf("%d\n", p->data);
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

void inorder(struct Node * p) {
    if (p) {
        inorder(p->lchild);
        printf("%d\n", p->data);
        inorder(p->rchild);
    }
}

void postorder(struct Node * p) {
    if (p) {
        postorder(p->lchild);
        postorder(p->rchild);
        printf("%d\n", p->data);
    }
}

int main() {
    treeCreate();
    preorder(root);
    postorder(root);
    return 0;   
}
#include <stdio.h>
#include <stdlib.h>

struct Node {
    struct Node * prev;
    int data;
    struct Node *next;
};

void Create(int A[],int n,struct Node * &head) {
    struct Node * temp;
    struct Node * last;
    head = (struct Node *)malloc(sizeof(struct Node));
    head->data = A[0];
    head->prev = head->next = NULL;
    last = head;
    for (int i = 1 ; i < n ; i++) {
        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->data = A[i];
        temp->next = last->next;
        temp->prev = last;
        last->next = temp;
        last = temp;
    }
}

void Display(struct Node * pos) {
    while(pos) {
        printf("%d\n",pos->data);
        pos = pos->next;
    }
}

int Length(struct Node * pos) {
    int len = 0 ;
    while(pos) {
        len++;
        pos = pos->next;
    }
    return len;
}

bool Insert(struct Node * pos,int index,int data,struct Node * &head) {
    struct Node * temp;
    if (index < 0 || index > Length(pos)) {
        return false;
    }
    if (index == 0) {
        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->data = data;
        temp->prev = NULL;
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
    else {
        for (int i = 0 ; i < index -1 ; i++) {
            pos = pos->next;
        }
        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->data = data;
        temp->prev = pos;
        temp->next = pos->next;
        if (pos->next) {
            pos->next->prev = temp;
        }
        pos->next = temp;
    }
    return true;
}

void Reverse(struct Node * pos, struct Node * &head) {
    struct Node * temp;
    while (pos) {
        temp = pos->next;
        pos->next = pos->prev;
        pos->prev = temp;
        if (!temp) {
            head = pos;
        }
        pos = pos->prev;
    }
}

int Delete(struct Node *pos,int index,struct Node * &head) {
    struct Node * q;
    int x = -1;
    if (index < 1 || index > Length(pos)) {
        return x;
    }
    if (index == 1) {
        head = head->next;
        if (head) {
            head->prev = NULL;
        }
        x = pos->data;
        free(pos);
    }
    else {
        for (int i = 0 ; i < index-1 ; i++) {
            pos = pos->next;
        }
        pos->prev->next = pos->next;
        if (pos->next) {
            pos->next->prev = pos->prev;
        }
        x = pos->data;
        free(pos);
    }
    return x;
}

int main() {
    int A[] = {1,3,5,7,9};
    struct Node * first;
    Create(A,5,first);
    Display(first);
    Reverse(first,first);
    Display(first);
    return 0;
}
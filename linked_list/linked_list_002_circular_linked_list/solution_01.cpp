#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node * next;
};

void Create(int A[],int n, struct Node * &head) {
    struct Node *temp;
    struct Node *last;
    head = (struct Node *)malloc(sizeof(struct Node));
    head->data = A[0];
    head->next = head;
    last = head;

    for(int i = 1 ; i < n ; i++) {
        temp  = (struct Node *)malloc(sizeof(struct Node));
        temp->data = A[i];
        temp->next = head;
        last->next = temp;
        last = temp;
    }
}

void Display(struct Node * pos, struct Node * &head) {
    do {
        printf("%d\n", pos->data);
        pos = pos->next;
    } while(pos != head);
}

int Length(struct Node * pos, struct Node * &head) {
    int len = 0;
    do {
        len++;
        pos = pos->next;
    } while(pos != head);
    return len;
}

bool Insert(struct Node * pos, struct Node * &head, int index, int data) {
    struct Node * temp;
    if (index < 0 || index > Length(pos,head)) {
        return false;
    }
    if (index == 0) {
        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->data = data;
        if (head == NULL) {
            head = temp;
            head->next = head;
        }
        else {
            while (pos->next != head) {
                pos = pos->next;
            }
            pos->next = temp;
            temp->next = head;
            head = temp;
        }
    }
    else {
        for (int i = 0; i < index - 1; i++) {
            pos = pos->next;
        }
        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->data = data;
        temp->next = pos->next;
        pos->next = temp;
    }
    return true;
}

int Delete(struct Node * pos, struct Node * &head, int index) {
    struct Node * q;
    int x = -1;
    if (index < 0 || index > Length(pos,head)) {
        return x;
    }
    if (index == 1) {
        while (pos->next != head) {
            pos = pos->next;
        }
        x = head->data;
        if (head == pos) {
            free(head);
            head = NULL;
        }
        else {
            pos->next = head->next;
            free(head);
            head = pos->next;
        }
    }
    else {
        for (int i = 0; i < index - 2 ; i++) {
            pos = pos->next;
        }
        q = pos->next;
        pos->next = q->next;
        x = q->data;
        free(q);
    }
    return x;
}

int main() {
    int A[] = {1,3,5,7,9,11};
    struct Node * head;
    Create(A,6,head);
    Display(head,head);
    Insert(head,head,1,2);
    Insert(head,head,0,87);
    Delete(head,head,1);
    Delete(head,head,3);
    Display(head,head);
    return 0;
}


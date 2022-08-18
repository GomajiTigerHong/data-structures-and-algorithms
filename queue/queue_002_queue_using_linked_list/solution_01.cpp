#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node * front = NULL;
struct Node * rear = NULL;

void enqueue(int x) {
    struct Node * temp;
    temp = (struct Node *)malloc(sizeof(struct Node));
    if (temp == NULL) {
        printf("queue is full\n");
    } else {
        temp -> data = x;
        temp -> next = NULL;
        if (front == NULL) {
            front = rear = temp;
        } else {
            rear -> next = temp;
            rear = temp;
        }
    }
}

int dequeue() {
    int x = -1;
    struct Node * temp;
    if (front == NULL) {
        printf("queue is empty\n");
    } else {
        x = front -> data;
        temp = front;
        front = front->next;
        free(temp);
    }
    return x;
}

void display() {
    struct Node * temp = front;
    while (temp) {
        printf("%d\n", temp->data);
        temp = temp -> next;
    }
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);

    display();

    dequeue();

    display();

    return 0;
}
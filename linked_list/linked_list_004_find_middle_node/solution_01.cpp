#include <iostream>
#include <cmath>
#include <stack>

using namespace std;

class Node {
    public:
        int data;
        Node * next;
};

Node * head = new Node;

void create(int A[], int n) {
    Node * temp;
    Node * tail;
    head->data = A[0];
    head->next = nullptr;
    tail = head;
    for (int i = 1 ; i < n ;i++) {
        temp = new Node;
        temp->data = A[i];
        temp->next = nullptr;
        tail->next = temp;
        tail = temp;
    }
}

void middleNodeOne(Node * pos) {
    int length = 0 ;
    while (pos) {
        length++;
        pos = pos->next;
    }
    int index = (int)ceil(length/2.0);
    Node * q = head;
    for (int i = 0 ; i < index-1;i++) {
        q = q->next;
    }
    cout << q->data << endl;
}

void middleNodeTwo(Node * pos) {
    Node * q = pos;
    while (q) {
        q = q->next;
        if (q) {
            q = q->next;
        }
        if (q) {
            pos = pos->next;
        }
    }
    cout << pos->data << endl;
}

void middleNodeThree(Node * pos) {
    stack<Node *> s;
    while(pos) {
        s.push(pos);
        pos = pos->next;
    }
    int length = s.size();
    int popLength = (int)(floor(length/2.0));
    while(popLength) {
        s.pop();
        popLength--;
    }
    cout << s.top()->data << endl;
}

void display(Node * pos) {
    while(pos) {
        cout << pos->data << endl;
        pos = pos->next;
    }
}

int main() {
    int A[] = {1,3,5,7,9,11,13};
    create(A,sizeof(A)/sizeof(A[0]));
    display(head);
    middleNodeOne(head);
    middleNodeTwo(head);
    middleNodeThree(head);
    return 0;
}
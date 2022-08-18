#include <iostream>
#include <cmath>
#include <stack>

using namespace std;

class Node {
    public:
        int data;
        Node * next;
};

Node * first = new Node;
Node * second = new Node;

void create(int A[], int n) {
    Node * temp;
    Node * tail;
    first->data = A[0];
    first->next = nullptr;
    tail = first;
    for (int i = 1 ; i < n ; i++) {
        temp = new Node;
        temp->data = A[i];
        temp->next = nullptr;
        tail->next = temp;
        tail = temp;
    }
}

void createSecond(int B[], int n, Node * pos) {
    Node * temp;
    Node * tail;

    second->data = B[0];
    second->next = nullptr;
    tail = second;
    for (int i = 1 ; i < n ; i++) {
        temp = new Node;
        temp->data = B[i];
        temp->next = nullptr;
        tail->next = temp;
        tail = temp;
    }
    tail->next = pos;
}

void display(Node * pos) {
    while (pos) {
        cout << pos->data << endl;
        pos = pos->next;
    }
}

void intersection(Node * p, Node * q) {
    //populate first stack
    stack<Node *> stk1;
    while (p) {
        stk1.push(p);
        p = p->next;
    }
    //populate second stack
    stack<Node *> stk2;
    while(q) {
        stk2.push(q);
        q = q->next;
    }

    Node * r;
    while (stk1.top() == stk2.top()) {
        r = stk1.top();
        stk1.pop();
        stk2.pop();
    }
    cout << r->data << endl;
}

int main() {
    //create first node
    int A[] = {1,3,5,7,9,11,13,15,17,19,21};
    create(A,sizeof(A)/sizeof(A[0]));
    //create second node
    Node * temp = first;
    int i = 5;
    while(i > 0) {
        temp = temp->next;
        i--;
    } 
    int B[] = {2,4,6,8,10};
    createSecond(B,sizeof(B)/sizeof(B[0]),temp);

    display(first);
    display(second);

    intersection(first, second);
    return 0;
}
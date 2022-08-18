#include <iostream>
#include <cstring>
#include <stack>

using namespace std;

class Node {
    public : 
        int data;
        Node * next;
};

class Stack {
    private :
        Node * top;
    public :
        Stack();
        ~Stack();
        void push(int x);
        int pop();
        int peek(int index);
        int isEmpty();
        int isFull();
        int stackTop();
};

Stack::Stack() {
    top = nullptr;
}

Stack::~Stack() {
    Node * temp = top;
    while (top) {
        top = top->next;
        delete temp;
        temp = top;
    }
}

void Stack::push(int x) {
    Node * temp = new Node;
    if (temp == nullptr) {
        cout << "stack overflow" << endl;
    } else {
        temp->data = x;
        temp->next = top;
        top = temp;
    }
}

int Stack::pop() {
    Node * temp;
    int x = -1;
    if (top == nullptr) {
        cout << "stack underflow" << endl;
    } else {
        temp = top;
        x = temp->data;
        top = top->next;
        delete temp;
    }
    return x;
}

int Stack::isFull() {
    Node * temp = new Node;
    int r = temp ? 1 : 0;
    delete temp;
    return r;
}

int Stack::isEmpty() {
    return top ? 0 : 1;
}

int Stack::stackTop() {
    if (top) {
        return top->data;
    }
    return -1;
}

int Stack::peek(int index) {
    if (isEmpty()) {
        return -1;
    } else {
        Node * temp = top;
        for (int i = 0; temp != nullptr && i < index - 1; i++) {
            temp = temp->next;
        }
        if (temp != nullptr) {
            return temp->data;
        } else {
            return -1;
        }
    }
}
int isOperand(char x) {
    if (x == '+' || x == '-' || x == '*' || x == '/') {
        return 0;
    }
    return 1;
}

int operation(char op, int x, int y) {
    if (op == '+') {
        return x + y;
    } else if (op == '-') {
        return x - y;
    } else if (op == '*') {
        return x * y;
    } else if (op == '/') {
        return x / y;
    }
    return -1;
}

int postfixEvaluate(char * postfix) {
    stack<int> stk;
    int x;
    int y;
    int result;
    for (int i = 0; postfix[i] != '\0'; i++) {
        if (isOperand(postfix[i])) {
            stk.push(postfix[i] - '0');
        } else {
            y = stk.top();
            stk.pop();
            x = stk.top();
            stk.pop();
            result = operation(postfix[i], x, y);
            stk.push(result);
        }
    }
    result = stk.top();
    stk.pop();
    return result;
}

int evaluate(char * postfix) {
    Stack stk;
    int x;
    int y;
    int result;
    for (int i = 0; postfix[i] != '\0'; i++) {
        if (isOperand(postfix[i])) {
            stk.push(postfix[i] - '0');
        } else {
            y = stk.pop();
            x = stk.pop();
            result = operation(postfix[i], x, y);
            stk.push(result);
        }
    }
    result = stk.pop();
    return result;
}

int main() {
    char postfix[] = "35*62/+4-";
    cout << evaluate(postfix) << endl;
    return 0;
}
#include <iostream>
#include <cstring>
#include <stack>

using namespace std;

int isOperand(char x) {
    if (x == '+' || x == '-' || x == '*' || x == '/' || x == '^' || x == '(' || x == ')') {
        return 0;
    }
    return 1;
}

int outPrecedence(char x) {
    if (x == '+' || x == '-') {
        return 1;
    }
    if (x == '*' || x == '/') {
        return 3;
    }
    if (x == '^') {
        return 6;
    }
    if (x == '(') {
        return 7;
    }
    if (x == ')') {
        return 0;
    }
    return -1;
}

int inPrecedence(char x) {
    if (x == '+' || x == '-') {
        return 2;
    }
    if (x == '*' || x == '/') {
        return 4;
    }
    if (x == '^') {
        return 5;
    }
    if (x == '(') {
        return 0;
    }
    return -1;
}

char * convert(char * infix) {
    char * postfix = new char [strlen(infix) + 1];
    stack<char> stk;
    int i = 0;
    int j = 0;
    while (infix[i] != '\0') {
        if (isOperand(infix[i])) {
            postfix[j++] = infix[i++];
        }
        if (!isOperand(infix[i])) {
            if (stk.empty() || outPrecedence(infix[i]) > inPrecedence(stk.top())) {
                stk.push(infix[i++]);
            } else if (outPrecedence(infix[i]) == inPrecedence(stk.top())) {
                stk.pop();
            } else {
                postfix[j++] = stk.top();
                stk.pop();
            }
        }
    }
    while (!stk.empty() && stk.top() != ')') {
        postfix[j++] = stk.top();
        stk.pop();
    }
    postfix[j] = '\0';
    return postfix;
}

int main() {
    char infix[] = "((a+b)*c)-d^e^f";
    cout << convert(infix) << endl;
    return 0;
}
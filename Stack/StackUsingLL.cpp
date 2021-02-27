#include <iostream>

using namespace std;

struct Node {
    int data;
    struct Node *next;
} *top = NULL;

void push(int x) {
    Node *t = new Node;
    if (t == NULL) { cout << "Stack overflow" << endl; }
    else {
        t->data = x;
        t->next = top;
        top = t;
    }
}

int pop() {
    int x = -1;
    Node *p = NULL;
    p = top;
    if (top == nullptr)
        cout << "Stack underflow!" << endl;
    else {
        top = top->next;
        x = p->data;
        delete p;
    }
    return x;
}

int peek(int pos) {
    Node *p = NULL;
    p = top;
    for (int i = 0; i < pos - 1; i++) {
        p = p->next;
    }
    if (p != NULL)
        return p->data;
    else
        return -1;
}

void displayStack() {
    Node *p = NULL;
    p = top;
    cout<<"Elements of stack are :"<<endl;
    while (p != NULL) {
        cout << p->data << endl;
        p = p->next;
    }
}

int main() {
    int A[] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; i++)
        push(A[i]);

    displayStack();
    cout<<endl;
    int c = pop();
    cout<<"Popped Element :"<<c<<endl;
    displayStack();
    cout<<endl;
    cout<<"Peeked Element :"<<peek(2)<<endl;
    return 0;
}
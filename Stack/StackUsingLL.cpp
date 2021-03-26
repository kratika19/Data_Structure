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
    for (int i = 0; i < pos-1; i++) {
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

    int x;
    int choice;
    while (true) {
        cout << "*******STACK MENU*******" << endl;
        cout << "Press 1 to push a value into stack" << endl;
        cout << "Press 2 to pop a value from stack" << endl;
        cout << "Press 3 to peek any value" << endl;
        cout << "Press 4 to display the elements of stack" << endl;
        cout << "Press 5 to exit" << endl;
        cout << "Make your choice :" << endl;
        cin >> choice;
        if (choice != 5) {
            switch (choice) {
                case 1: {
                    cout << "Enter the value to be pushed :" << endl;
                    cin >> x;
                    push(x);
                    cout << endl;
                    break;
                }
                case 2: {
                    int a = pop();
                    cout << endl;
                    break;
                }
                case 3: {
                    int pos;
                    cout << "Enter position where you want to peak the value :" << endl;
                    cin >> pos;
                    int val = peek(pos);
                    cout << "Value at position " << pos << " in stack is " << val << endl;
                    cout << endl;
                    break;
                }
                case 4: {
                    cout << "Stack contents are:" << endl;
                    displayStack();
                    cout << endl;
                    break;
                }
                default: {
                    cout << "Invalid choice entered" << endl;
                    cout << endl;
                    break;
                }

            }
        } else {
            break;
        }
    }
    return 0;
}

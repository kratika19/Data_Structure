#include <iostream>

using namespace std;

struct Node {
    int data;
    struct Node *next;
} *head;

void createCLL(int A[], int n) {
    struct Node *t, *last;
    last = new Node;
    head = new Node;
    head->data = A[0];
    head->next = head;
    last = head;
    for (int i = 1; i < n; i++) {
        t = new Node;
        t->data = A[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }
}

void deleteNode(int pos, int n) {
    struct Node *t, *p;
    p = head;
    t = head->next;
    if (pos == 0) {
        while (p->next != head)
            p = p->next;
        p->next = t;
        delete head;
        head = t;
    } else {

        if (pos > 0 && pos < n) {
            for (int i = 0; i < pos - 1; i++) {
                p = p->next;
                t = t->next;
            }
            p->next = t->next;
            delete t;
        } else {
            cout << "Invalid index given for deletion" << endl;
        }
    }
}

void display(struct Node *p) {
    int flag = 0;
    while (flag != 1 || p != head) {
        flag = 1;
        cout << p->data << endl;
        p = p->next;
    }
}


int main() {
    int A[] = {1, 2, 3, 4};
    createCLL(A, 4);
    display(head);
    cout << endl;
    int pos = 1;//position of deletion
    int n = 4; //size of array
    deleteNode(pos - 1, n);
    cout << endl;
    display(head);
    cout << endl;
    return 0;
}


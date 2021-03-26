#include <iostream>

using namespace std;

struct Node {
    struct Node *prev;
    int data;
    struct Node *next;
} *first = NULL;

void createDLL(int A[], int n) {
    struct Node *t, *last;
    first = new Node;
    first->data = A[0];
    first->prev = first->next = NULL;
    last = first;

    for (int i = 1; i < n; i++) {
        t = new Node;
        t->data = A[i];
        t->next = last->next;
        t->prev = last;
        last->next = t;
        last = t;
    }
}

void insert(struct Node *p, int pos, int x) {
    struct Node *t = NULL;
    t = new Node;
    t->data = x;
    if (pos == 0) {
        t->next = first;
        t->prev = NULL;
        first = t;
    } else {
        for (int i = 0; i < pos - 1; i++) {
            p = p->next;
        }
        t->prev = p;
        t->next = p->next;
        if (p->next != NULL) {
            p->next->prev = t;
        }
        p->next = t;
    }
}

void displayLL(struct Node *p) {
    while (p != NULL) {
        cout << p->data << endl;
        p = p->next;
    }
}

int main() {
    int A[] = {78, 98, 25, 32, 42};
    int n = 5;
    createDLL(A, n);
    displayLL(first);
    cout<<endl;
    int pos = 1;
    int x = 90;
    insert(first, pos - 1, x);
    displayLL(first);
    cout<<endl;
    pos = 4;
    x = 222;
    insert(first, pos - 1, x);
    displayLL(first);
    cout<<endl;
    pos = 8;
    x = 2002;
    insert(first, pos - 1, x);
    displayLL(first);
    cout<<endl;
    return 0;
}
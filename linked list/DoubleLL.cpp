#include <iostream>

using namespace std;

struct Node {
    struct Node *prev;
    int data;
    struct Node *next;
} *first = NULL;

void createLL(int A[], int n) {
    struct Node *t, *last = NULL;
    first = new Node;
    first->prev = first->next = NULL;
    first->data = A[0];
    last = first;
    for (int i = 1; i < n; i++) {
        t = new Node;
        t->data = A[i];
        t->prev = last;
        t->next = last->next;
        last->next = t;
        last = t;
    }
}

void display(struct Node *p) {
    while (p != NULL) {
        cout << p->data << endl;
        p = p->next;
    }
}

int main() {
    int A[] = {1, 2, 3, 4, 5};
    int n = 5;
    createLL(A, n);
    display(first);
}
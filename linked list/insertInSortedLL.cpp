#include <iostream>

using namespace std;

struct Node {
    int data;
    struct Node *next;
} *first = NULL, *last = NULL;

void insertLast(int x) {
    struct Node *t = new Node;
    t->next = NULL;
    t->data = x;
    if (first == NULL) {
        first = last = t;
    } else {
        last->next = t;
        last = t;
    }
}

void insertSorted(struct Node *p, int x) {
    struct Node *t = new Node;
    struct Node *q = NULL;
    t->data = x;
    t->next = NULL;
    if (first == NULL)
        first = t;

    else {
        while (p->data < x && p) {
            q = p;
            p = p->next;
        }
        if (p == first) {
            t->next = first;
            first = t;
        } else {
            t->next = q->next;
            q->next = t;
        }
    }
}

void display(struct Node *p) {
    while (p != NULL) {
        cout << p->data << endl;
        p = p->next;
    }
}

int main() {
    int A[] = {3, 7, 9, 15, 28};
    int size = sizeof(A) / sizeof(A[0]);
    for (int i = 0; i < size; i++) {
        insertLast(A[i]);
    }
    display(first);
    cout << endl;
    insertSorted(first, 14);
    display(first);
    cout << endl;
    insertSorted(first, 1);
    display(first);
    return 0;
}


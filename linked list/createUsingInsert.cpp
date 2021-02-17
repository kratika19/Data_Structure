#include <iostream>

using namespace std;

struct Node {
    int data;
    struct Node *next;
} *first = NULL;

void create(int A[], int n) {
    struct Node *last, *t = NULL;
    last = new Node;
    first->data = A[0];
    first->next = NULL;
    last = first;
    for (int i = 1; i < n; i++) {
        t = new Node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void insert(int pos, int value) {
    struct Node *t = NULL;
    struct Node *p = NULL;
    t = new Node;
    t->data = value;
    if (pos == 0) {
        t->next = first;
        first = t;
    } else {
        p = first;
        for (int i = 1; i < pos - 1; i++) {
            p = p->next;
        }
        t->next = p->next;
        p->next = t;
    }
}

void display(struct Node *p) {
    while (p != NULL) {
        cout << p->data << endl;
        p = p->next;
    }
}

int main() {
    first = new Node;
//    int A[] = {78, 23, 69, 10, 22, 45};
    int A[0];

//    display(first);
    cout<<endl;
    insert(0, 15);
    insert(1, 25);
    insert(2, 35);
    insert(3, 45);
    insert(4, 55);
    insert(5, 65);
    create(A, 6);

    display(first);
    return 0;
}


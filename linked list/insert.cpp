#include <iostream>

using namespace std;

struct Node {
    int data;
    struct Node *next;
} *first = NULL;

void create(int A[], int n) {
    struct Node *last, *t;
    last = new Node;
    last->data = A[0];
    last->next = NULL;
    first = last;
    for (int i = 1; i < n; i++) {
        t = new Node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void insert(struct Node *p, int pos) {
    struct Node *t;
    t = new Node;
    t->data = 98;
    if (pos == 0) {
        t->next = first;
        first = t;
    } else {
        for(int i=1;i<pos-1;i++)
        {
            p=p->next;
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
    int A[] = {78, 23, 69, 10, 22, 45};
    create(A,6);
    display(first);
    cout<<endl;
    insert(first, 7);
    display(first);
    return 0;
}
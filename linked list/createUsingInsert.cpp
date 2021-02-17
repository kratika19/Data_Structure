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

void display(struct Node *p) {
    while (p != NULL) {
        cout << p->data << endl;
        p = p->next;
    }
}

int main() {
    int A[] = {8,9,6,5,4,2,1,0};
    for(int i=0;i<8;i++)
    {
        insertLast(A[i]);
    }
    insertLast(5);
    insertLast(6);
    insertLast(7);
    display(first);
    return 0;
}


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
//reverse using reversing links using slider pointers
void reverseLL(struct Node *p) {
    struct Node *q, *r ;
    q = NULL;
    r = NULL;
    while(p!=0)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
}

void display(struct Node *p) {
    while (p != NULL) {
        cout << p->data << endl;
        p = p->next;
    }
}

int main() {
    int A[] = {1,2,3,4};
    for (int i = 0; i < 4; i++) {
        insertLast(A[i]);
    }
    display(first);
    cout << endl;
    reverseLL(first);
    display(first);
    cout << endl;
    return 0;
}


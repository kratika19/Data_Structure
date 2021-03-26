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

void deleteLL(int pos) {
    struct Node *p=first;
    if(pos==0)
    {
        first = first->next;
        if(first)
        first->prev = nullptr;
        delete p;
    }
    else{
        for(int i=0;i<pos;i++)
            p=p->next;
        p->prev->next = p->next;
        if(p->next)
            p->next->prev = p->prev;
        delete p;
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
    deleteLL(5-1);
    displayLL(first);
    cout<<endl;
    return 0;
}

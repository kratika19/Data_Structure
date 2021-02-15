#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    struct Node *next;
} *first = NULL;

void createLL(int A[], int n) {
    struct Node *t, *last;
    first = (struct Node *) malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (int i = 1; i < n; i++) {
        t = (struct Node *) malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void insertLL(struct Node *p, int pos) {
    struct Node *t;
    t = (struct Node *) malloc(sizeof(struct Node));
    t->data = 7;
    if (pos == 0) {
        t->next = first;
        first = t;
    } else {
        p = first;
        for (int i = 0; i < pos - 1; i++) {
            p = p->next;
        }
        t->next = p->next;
        p->next = t;
    }
}

void display(struct Node *p)
{
    if(p!=0)
    {
        cout<<p->data<<endl;
        display(p->next);
    }
}

int main() {
    int A[] = {1, 2, 3, 4, 5};
    createLL(A,5);
    display(first);
    int pos;
    cout << "Enter position where you wish to insert the new node:" << endl;
    cin >> pos;
    insertLL(first, pos);
    display(first);
    return 0;
}
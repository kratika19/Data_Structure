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

void display(struct Node *p) {
    int flag = 0;
    while (flag != 1 || p != head) {
        flag = 1;
        cout << p->data << endl;
        p = p->next;
    }
}


bool isLoop(struct Node *f) {
    bool check = false;
    struct Node *p, *q;
    p = q = f;
    do {
        p = p->next;
        q = q->next;
        if (q != NULL)
            q = q->next;
        if (p == q) {
            check = true;
            break;
        }
    } while (p != NULL && q != NULL);
    return check;
}


int main() {
    int A[] = {1, 2, 3, 4};
    createCLL(A, 4);
    display(head);
    cout << endl;
    bool check = isLoop(head);
    if (check)
        cout << "Loop is present in the Linked List" << endl;
    else
        cout << "Loop is absent in the linked list" << endl;
    cout << endl;
    return 0;
}


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

int countNode(struct Node *p) {
    int count = 0;
    while (p != NULL) {
        count++;
        p = p->next;
    }
    return count;
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

void display(struct Node *p) {
    while (p != NULL) {
        cout << p->data << endl;
        p = p->next;
    }
}

int main() {
    int A[] = {1, 2, 3, 4};
    for (int i = 0; i < 4; i++) {
        insertLast(A[i]);
    }
    display(first);
    cout << endl;
    bool check = isLoop(first);
    if(check)
        cout<<"Loop is present in the Linked List"<<endl;
    else
        cout<<"Loop is absent in the linked list"<<endl;
    return 0;
}


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

void reverseLL(struct Node *p) {
    int n = countNode(first);
    int A[n];
    int i = 0;
    while (p != NULL) {
        A[i] = p->data;
        i++;
        p = p->next;
    }
    p = first;
    i--;
    while (p != NULL) {
        p->data = A[i];
        i--;
        p = p->next;
    }
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


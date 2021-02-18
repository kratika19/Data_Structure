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

void insert(int pos, int x) {
    struct Node *t, *p;
    t = new Node;
    t->next = nullptr;
    t->data = x;
    p = head;
    if (pos == 0) {
        if(head == NULL){
            head = t;
            head->next = head;
        }
        else{
            while (p->next != head)
                p = p->next;
            t->next = head;
            p->next = t;
            head = t;
        }
    } else {
        for (int i = 0; i < pos - 1; i++)
            p = p->next;
        t->next = p->next;
        p->next = t;
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


int main() {
    int A[] = {1, 2, 3, 4};
    createCLL(A, 4);
    display(head);
    cout << endl;
    int pos = 5;//position of insertion
    int x = 8;//value to be inserted
    insert(pos-1, x);
    display(head);
    cout << endl;
    return 0;
}


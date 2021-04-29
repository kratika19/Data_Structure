#include <iostream>
#include "Queue.h"

using namespace std;

Node *root = NULL;

void createNode() {
    Node *p;
    Node *t;
    Queue q;

    create(&q, 100);

    cout << "Enter root value :";
    int value;
    cin >> value;

    root = new Node;
    root->data = value;
    root->lchild = root->rchild = 0;

    Enqueue(&q, root);

    while (!isEmpty(q)) {
        p = Dequeue(&q);
        cout << "Enter value of left child of " << p->data << " (enter -1 if does not exist) :";
        cin >> value;
        if (value != -1) {
            t = new Node;
            t->data = value;
            t->lchild = t->rchild = 0;
            p->lchild = t;
            Enqueue(&q, t);
        }
        cout << "Enter value of right child of " << p->data << " (enter -1 if does not exist) :";
        cin >> value;
        if (value != -1) {
            t = new Node;
            t->data = value;
            t->lchild = t->rchild = 0;
            p->rchild = t;
            Enqueue(&q, t);
        }
    }
}

void preorder(Node *p) {
    if (p) {
        cout << p->data << " -> ";
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

int main() {
    cout << "Welcome to binary tree creation" << endl;
    createNode();

    cout<<"Preorder Traversal is : ";
    preorder(root);
    cout<<"end";
    return 0;
}
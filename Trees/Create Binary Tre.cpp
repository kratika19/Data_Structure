#include <iostream>
#include "Queue.h"

using namespace std;

struct Stack {
    int size;
    int top;
    Node **Ar;
};

void push(Stack *s, Node* x) {
    if (s->top == s->size - 1) {
        return;
    } else {
        (s->top)++;
        s->Ar[s->top] = x;
    }
}

int isEmpty(Stack s) {
    return (s.top == -1);
}

Node* pop(Stack *s) {
    Node* x = NULL;
    if (s->top == -1)
        x = NULL;
    else {
        x = s->Ar[s->top];
        (s->top)--;
    }
    return x;
}


Stack st;
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

void iterPreorder(Node* p)
{
    st.size = 100;
    st.Ar = new Node*[st.size];

    while(p!= NULL || !isEmpty(st))
    {
        if(p!=NULL)
        {
            cout << p->data << " -> ";
            push(&st, p);
            p = p->lchild;
        }
        else{
            p = pop(&st);
            p = p->rchild;
        }
    }
}

void inorder(Node *p) {
    if (p) {
        inorder(p->lchild);
        cout << p->data << " -> ";
        inorder(p->rchild);
    }
}

void iterInorder(Node* p)
{
    st.size = 100;
    st.Ar = new Node*[st.size];

    while(p!= NULL || !isEmpty(st))
    {
        if(p!=NULL)
        {
            push(&st, p);
            cout << p->data << " -> ";
            p = p->lchild;
        }
        else{
            p = pop(&st);
            p = p->rchild;
        }
    }
}

void postorder(Node *p) {
    if (p) {
        postorder(p->lchild);
        postorder(p->rchild);
        cout << p->data << " -> ";
    }
}

void iterPostorder(Node* p)
{
    st.size = 100;
    st.Ar = new Node*[st.size];

    while(p!= NULL || !isEmpty(st))
    {
        if(p!=NULL)
        {
            push(&st, p);
            p = p->lchild;
            cout << p->data << " -> ";
        }
        else{
            p = pop(&st);
            p = p->rchild;
        }
    }
}

int main() {
    cout << "Welcome to binary tree creation" << endl;
    createNode();

    cout<<endl<<endl;

    cout<<"Preorder Traversal is : ";
    preorder(root);
    cout<<"end"<<endl;

    cout<<"Inorder Traversal is : ";
    inorder(root);
    cout<<"end"<<endl;

    cout<<"Postorder Traversal is : ";
    postorder(root);
    cout<<"end"<<endl;

//    cout<<"Preorder Traversal is : ";
//    iterPreorder(root);
//    cout<<"end"<<endl;

//    cout<<"Inorder Traversal is : ";
//    iterInorder(root);
//    cout<<"end"<<endl;
//
//    cout<<"Postorder Traversal is : ";
//    iterPostorder(root);
//    cout<<"end"<<endl;
    return 0;
}
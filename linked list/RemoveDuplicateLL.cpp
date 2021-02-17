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

bool checkSorted(struct Node *p)
{
    bool check = true;
    struct Node *t = first->next;
    while(p!=NULL && t!=NULL)
    {
        if(t->data < p->data)
        {
            check = false;
            break;
        }
        p = p->next;
        t = t->next;
    }
    return check;
}


void deleteNode(struct Node *p, int pos) {
    struct Node *t = first->next;
    if (pos == 0) {
        first = first->next;
        delete p;
    } else {
        for (int i = 0; i < pos - 1; i++) {
            t = t->next;
            p = p->next;
        }
        p->next = t->next;
        delete t;
    }
}

void removeDuplicates(struct Node *p)
{
    int pos = 0;
    struct Node *t = first->next;
    while(t!=NULL)
    {
        pos++;
        if(t->data == p->data)
        {
            deleteNode(first , pos-1);
            p->next = t->next;
            t = t->next;
        }
        else
        {
            p = p->next;
            t = t->next;
        }

    }
}

void display(struct Node *p) {
    while (p != NULL) {
        cout << p->data << endl;
        p = p->next;
    }
}

int main() {
    int A[] = {1,2,2,4,4,5,6};
    for(int i=0;i<7;i++)
    {
        insertLast(A[i]);
    }
    display(first);

    bool isSorted = checkSorted(first);

    if(isSorted) {
        cout << endl << "Linked List is sorted" << endl;
        removeDuplicates(first);
        display(first);
    }
    else
        cout<<endl<<"Linked List is not sorted"<<endl;
    return 0;
}




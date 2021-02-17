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

void display(struct Node *p) {
    while (p != NULL) {
        cout << p->data << endl;
        p = p->next;
    }
}

int main() {
    int A[] = {1,2,8,4};
    for(int i=0;i<4;i++)
    {
        insertLast(A[i]);
    }
    display(first);

    bool isSorted = checkSorted(first);

    if(isSorted)
        cout<<endl<<"Linked List is sorted"<<endl;
    else
        cout<<endl<<"Linked List is not sorted"<<endl;
    return 0;
}




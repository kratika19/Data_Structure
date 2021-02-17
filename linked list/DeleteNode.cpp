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
void deleteNode(struct Node *p , int pos)
{
    struct Node *t = first->next;
    if(pos == 0)
    {
        first = first -> next;
        delete p;
    }
    else{
        while(p!=NULL)
        {
            for(int i=0;i<pos-1;i++)
            {
                t = t->next;
                p = p->next;
            }
            p->next = t->next;
            delete t;
            break;
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
    int A[] = {8,9,6,5,4,2,1,0};
    for(int i=0;i<8;i++)
    {
        insertLast(A[i]);
    }
    display(first);
    cout<<endl;
    int pos = 1;
    deleteNode(first,pos -1); //node at position 1 will be deleted
    display(first);
    cout<<endl;
    pos = 4;
    deleteNode(first,pos-1); //node at position 4 will be deleted
    display(first);
    cout<<endl;
    pos = 6;
    deleteNode(first,pos-1); //node at position 4 will be deleted
    display(first);
    return 0;

}


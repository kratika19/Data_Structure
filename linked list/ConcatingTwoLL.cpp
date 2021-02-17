
#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *next;
}*first = NULL, *second = NULL, *third = NULL;

void createLL(int A[] , int n, int B[] , int m)
{
    struct Node *t1,*last1;
    first = new Node;
    first->data = A[0];
    first->next = NULL;
    last1 = first;
    for(int i=1;i<n;i++)
    {
        t1 = new Node;
        t1->data = A[i];
        t1->next = NULL;
        last1->next = t1;
        last1 = t1;
    }

    struct Node *t2,*last2;
    second = new Node;
    second->data = B[0];
    second->next = NULL;
    last2 = second;
    for(int i=1;i<m;i++)
    {
        t2 = new Node;
        t2->data = B[i];
        t2->next = NULL;
        last2->next = t2;
        last2 = t2;
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

void concat(struct Node *f , struct Node *s)
{
    third = f;
    while(f->next!=NULL)
        f = f->next;
    f->next = s;
}

int main()
{
    int A[] = { 1, 2, 3, 4, 5};
    int B[] = { 1, 2, 3, 4, 5};
    createLL(A,5,B,5);
    display(first);
    cout<<endl;
    display(second);
    cout<<endl;
    concat(first , second);
    display(third);
    cout<<endl;
    return 0;
}
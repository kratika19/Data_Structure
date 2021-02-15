
#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *next;
}*first = NULL;

void createLL(int A[] , int n)
{
    struct Node *t,*last;
    first = (struct Node*)malloc(sizeof (struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;

    for(int i=1;i<n;i++)
    {
        t = (struct Node*)malloc(sizeof (struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
    struct Node *p;
    p = first;
    while(p!=0)
    {
        cout<<p->data;
        p = p->next;
    }
}
int main()
{
    int A[] = { 1, 2, 3, 4, 5};
    createLL(A,5);
    return 0;
}
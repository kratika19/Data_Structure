
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
}
int maxLL(struct Node *p)
{
    int max = p->data;
    while (p!=0){
        if(max<p->data)
            max = p->data;
        p = p->next;
    }
    return max;
}
int main()
{
    int A[] = { 1, 2, 27, 4, 5};
    createLL(A,5);
    cout<<maxLL(first);
    return 0;
}
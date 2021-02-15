
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
int addLL(struct Node *p)
{
//    int sum =0;
//    while (p!=0){
//        sum+= p->data;
//        p=p->next;
//    }
//    return sum;

    if(p==0)
        return 0;
    else return addLL(p->next)+p->data;
}
int main()
{
    int A[] = { 1, 2, 3, 4, 5};
    createLL(A,5);
    cout<<addLL(first);
    return 0;
}
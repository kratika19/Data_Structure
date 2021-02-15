//
// Created by krati on 09-02-2021.
//
//
// Created by krati on 09-02-2021.
//

//
// Created by krati on 09-02-2021.
//

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
bool search(struct Node *p , int n)
{
    bool result = false;
    while(p!=0)
    {
        if (n == p->data)
        {
            result = true;
            break;
        }
        p = p->next;
    }
    return result;
}
int main()
{
    int A[] = { 1, 2, 27, 4, 5};
    createLL(A,5);
    int n;
    cout<<"Enter the number to be searched :"<<endl;
    cin>>n;
    bool check = search(first,n);
    if(check)
    {
        cout<<"Number found"<<endl;
    }
    else{
        cout<<"Number not found"<<endl;
    }
    return 0;
}

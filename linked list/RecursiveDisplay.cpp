//
// Created by krati on 09-02-2021.
//

#include <bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    struct Node* next;
}*first = NULL;
//******************************linked list creation***************************************
void createLL(int A[], int n)
{
    first = (struct Node*)malloc(sizeof(struct Node));
    struct Node *t, *last;
    first ->data = A[0];
    first ->next = NULL;
    last = first;

    for(int i=1;i<n;i++)
    {
        t = (struct Node*)malloc(sizeof(struct Node));
        t ->data = A[i];
        t ->next = NULL;
        last ->next = t;
        last = t;
    }
}
//**********************display recursion using linked list***************************************
void displayLL(struct Node *p)
{
    if(p!=0)
    {
        cout<<p->data<<endl;
        displayLL(p->next);
    }
}
//*************************display reverse linked list using recursion*******************************
void displayReverseLL(struct Node *p)
{
    if(p!=0)
    {
        displayReverseLL(p->next);
        cout<<p->data<<endl;
    }
}
//*******************length of linked list******************************
//int totalNodes(struct Node *p){
//    int count = 0;
//    while(p!=NULL)
//    {
//        count++;
//        p = p->next;
//    }
//    return count;
//}
int totalNodes(struct Node *p){
//    if(p==0)
//        return  0;
//    else
//        return totalNodes(p->next)+1;
   return p==0? 0 : totalNodes(p->next)+1;
}
//***********************************main function******************************************************
int main(){
    int A[] = { 1,2,3,4,5};
    createLL(A , 5);
    displayLL(first);
    cout<<endl;
    displayReverseLL(first);
    cout<<endl;
    cout<<totalNodes(first)<<endl;
    return 0;
}
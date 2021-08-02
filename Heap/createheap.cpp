//
// Created by krati on 02-08-2021.
//

#include<iostream>
using namespace std;

void insertHeap(int A[], int n){
    int i = n;
    int temp = A[n];
//    i = i/2;
    while(i > 1 && A[i/2] < temp )
    {
        A[i] = A[i/2];
        i = i/2;
    }

    A[i] = temp;
}

int main()
{
    int n;
    cout<<"Enter number of elements of the array to make heap :";
    cin>>n;

    int A[n+1];
    A[0] = 0;
    cout<<"Enter elements of the array to make heap :";
    for(int i=1;i<=n;i++)
    {
        cin>>A[i];
    }

    for(int i=2;i<=n;i++)
    {
        insertHeap(A, i);
    }

    for(int i=1;i<=n;i++)
    {
        cout<<A[i]<<" ";
    }
}

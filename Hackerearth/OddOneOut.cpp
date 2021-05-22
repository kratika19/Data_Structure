//
// Created by krati on 22-05-2021.
//

#include<iostream>
using namespace std;

void Swap(int &a, int &b)
{
    int t;
    t = a;
    a = b;
    b = t;
}

void BubbleSort(int* A, int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(A[j]>A[j+1])
            Swap(A[j], A[j+1]);
        }
    }
}

int OddOneOut(int* A,int n)
{
    int i = 0;
    int diff = 2;
    while(diff == 2 && i<n)
    {
        diff = A[i+1]-A[i];
        i++;
    }
    return A[i]-2;
}
int main()
{
    int n;
    int* A;
    cin>>n;
    A = new int[n-1];
    for(int i=0;i<n-1;i++)
    cin>>A[i];
    BubbleSort(A,n-1);
    int a = OddOneOut(A,n-1);
    cout<<a<<endl;
}

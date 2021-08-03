//
// Created by krati on 03-08-2021.
//
#include<iostream>
using namespace std;
void Adjust(int A[], int i, int j, int n)
{
    if(A[j+1] > A[j])
        j = j + 1;

    if(A[j] > A[i])
    {
        int temp = A[j];
        A[j] = A[i];
        A[i] = temp;

        if(j*2 < n)
        {
            Adjust(A, j, j*2, n);
        }
    }
}


void Heapify(int A[], int n){
    int i = n/2 - 1;
    int j;
    while(i != 0)
    {
        j = 2*i;
        Adjust(A, i, j, n);
        i--;
    }
}

int main()
{
    int n = 8;
    int A[] = {0,10,20,30,25,5,40,35};

    Heapify(A, n);

    for(int i=1;i<n;i++)
        cout<<A[i] <<" ";
    return 0;
}


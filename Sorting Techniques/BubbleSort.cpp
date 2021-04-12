//
// Created by krati on 12-04-2021.
//

#include <iostream>
using namespace std;

void bubbleSort(int A[], int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(A[j]>A[j+1])
            {
                int temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
            }
        }
    }
    cout<<"Elements after sorting"<<endl;
    for(int i = 0;i<n;i++)
    {
        cout<<A[i]<<" ";
    }
}

int main()
{
    int A[] = {91,22,89,11,2,65,41,30,2};
    cout<<"Elements before sorting"<<endl;
    for(int i = 0;i<9;i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<endl;
    bubbleSort(A,9);
    return 0;
}
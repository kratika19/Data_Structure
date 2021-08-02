
#include<iostream>
using namespace std;

void insertHeap(int A[], int n){
    int i = n;
    int temp = A[n];
    while(i > 1 && A[i/2] < temp )
    {
        A[i] = A[i/2];
        i = i/2;
    }

    A[i] = temp;
}

void deleteHeap(int A[], int n){
    int temp, i, j;
    i = 1;
    j = 2*i;
    temp = A[1];
    A[1] = A[n];
    while(j < n-1)
    {
        if(A[j+1] > A[j])
            j = j+1;

        if(A[i] < A[j])
        {
            int s = A[i];
            A[i] = A[j];
            A[j] = s;

            i = j;
            j = 2*j;
        }
        else
        {
            break;
        }
    }
    A[n] = temp;
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
        deleteHeap(A, n+1-i);
    }

    for(int i=1;i<=n;i++)
    {
        cout<<A[i]<<" ";
    }
}



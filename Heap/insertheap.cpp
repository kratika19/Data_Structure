
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

int main()
{
    int n;
    cout<<"Enter number of elements of the array to make heap :";
    cin>>n;

    int A[n+5];
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

    A[n+1] = 80;
    insertHeap(A, n+1);

    for(int i=1;i<=n+1;i++)
    {
        cout<<A[i]<<" ";
    }
}

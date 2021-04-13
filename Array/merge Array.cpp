#include <iostream>

using namespace std;


void merge(int A[], int m, int B[], int n, int* C)
{
    int s = m+n;
    int a = 0;
    int b = 0;
    for(int i=0;i<s;i++)
    {
        if(a<=m && b<=n)
        {
            if(A[a]<B[b])
            {
                C[i] = A[a];
                a++;
            }
            else{
                C[i] = B[b];
                b++;
            }
        }
    }
}

int main()
{
    int m, n;
    cout<<"Enter size of Array 1 :";
    cin>>m;
    cout<<"Enter the elements of Array 1"<<endl;
    int A[m];
    for (int i = 0; i < m; ++i) {
        cin>>A[i];
    }
    cout<<endl;
    cout<<"Enter size of Array 2 :";
    cin>>n;
    cout<<"Enter the elements of Array 2"<<endl;
    int B[n];
    for (int i = 0; i < n; ++i) {
        cin>>B[i];
    }
    int* C = new int [m+n];

    merge(A,m,B,n,C);

    cout<<"Elements of new merged array are"<<endl;
    for (int i = 0; i < m+n; ++i) {
        cout<<C[i]<<" ";
    }

    cout<<endl;
}
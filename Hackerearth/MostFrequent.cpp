#include<iostream>
using namespace std;

// void Swap(int &a, int &b)
// {
//     int t;
//     t = a;
//     a = b;
//     b = t;
// }

// void BubbleSort(int* A, int n)
// {
//     for(int i=0;i<n-1;i++)
//     {
//         for(int j=0;j<n-i-1;j++)
//         {
//             if(A[j]>A[j+1])
//             Swap(A[j], A[j+1]);
//         }
//     }
// }
int MostFrequent(int* A, int n)
{
    int count1=0, count2=0;
    int pos=0;
    int index;
    for(int i=0;i<n;i++)
    {
        if(A[pos] == A[i])
            count1++;
        else{
            if(count2<count1)
            {
                index = i-1;
                count2 = count1;
            }
            count1 = 1;
            pos = i;
        }
    }
    return A[index];
}
int main()
{
    int n;
    int* A;
    cin>>n;
    A = new int[n-1];
    for(int i=0;i<n-1;i++)
        cin>>A[i];
    //BubbleSort(A,n-1);
    int a = MostFrequent(A,n);
    cout<<a<<endl;
}

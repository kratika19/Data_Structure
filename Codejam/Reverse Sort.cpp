//
// Created by krati on 03-08-2021.
//

#include<bits/stdc++.h>
using namespace std;

//void ReverseArray(int A[],int i, int pos)
//{
//    for(int j=i;j<=pos/2;j++)
//    {
//        int temp = A[j];
//        A[j] = A[pos - j + i];
//        A[pos - j + i] = temp;
//    }
//}
int ReverseCost(int A[], int n){
    int min;
    int cost=0;
    int pos;
    for(int i=0;i<n-1;i++)
    {
        min = A[i];
        pos = i;
        for(int j= i+1; j<n;j++)
        {
            if(A[j] < min)
            {
                min = A[j];
                pos = j;
            }
        }

        cost = cost + pos - i + 1;
        reverse(A+i, A+pos+1);
    }

    return cost;
}
int main(){
    int T;
    cin>>T;
    int a = 1;
    while(T--)
    {
        int n;
        cin>>n;
        int Arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>Arr[i];
        }

        int cost = ReverseCost(Arr, n);
        cout<<"Case #"<<a<<": "<<cost<<endl;
        a++;
    }
    return 0;
}
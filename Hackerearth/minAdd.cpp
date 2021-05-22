#include<iostream>
using namespace std;

int MinNo(int N, int K, int* A)
{
    int sum =0;
    int avg;
    int n = N;
    for(int i=0;i<N;i++)
    {
        sum = sum +  A[i];
    }
    avg = sum/N;
    if(avg<=K)
        return 0;
    else{
        int a = 1;
        while(true)
        {
            sum = sum + a;
            n++;
            a++;
            avg = sum/n;
            if(avg<=K)
                break;
            else
                continue;
        }
        return n-N;
    }
}

int main()
{
    int T, N, K;
    int* A;
    cin>>T;
    for(int i=0;i<T;i++)
    {
        cin>>N>>K;
        A = new int[N];
        for(int j =0;j<N;j++)
        {
            cin>>A[j];
        }
        int a = MinNo(N,K,A);
        cout<<a<<endl;
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;

map<int,long long> m;


long long tribonacci(int n) {
    
        if(m.count(n)>0)
		return m[n];
		
	if(n==0)
		return 0;
		
	if(n==1 || n==2)
		return 1;
	
	m[n] = tribonacci(n-1) + tribonacci(n-2) + tribonacci(n-3);
	
	return m[n];
    }


int main()
{
	cout<<tribonacci(5)<<endl;
	cout<<tribonacci(9)<<endl;
	cout<<tribonacci(15)<<endl;
	cout<<tribonacci(50)<<endl;
	
	return 0;
}

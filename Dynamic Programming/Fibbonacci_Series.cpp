#include<bits/stdc++.h>

using namespace std;

map<int,long long> m;


long long fibb(int n)
{
	if(m.count(n)>0)
		return m[n];
		
	if(n==0)
		return 0;
		
	if(n==1)
		return 1;
	
	m[n] = fibb(n-1) + fibb(n-2);
	
	return m[n];
}


int main()
{
	cout<<fibb(5)<<endl;
	cout<<fibb(9)<<endl;
	cout<<fibb(15)<<endl;
	cout<<fibb(50)<<endl;
	
	return 0;
}

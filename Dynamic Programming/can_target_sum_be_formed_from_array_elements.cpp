#include <bits/stdc++.h>
using namespace std;

//recursive call
bool canSum(int targetsum, vector<int> numbers)
{
    if (targetsum == 0) return true;
    
    for(int n=0;n<numbers.size();n++)
    {
        int remainder = targetsum - numbers[n];
        if(remainder >= 0)
            if(canSum(remainder, numbers) == true)
                return true;
    }
  
    return false;
}

int main()
{
    vector<int> v1 = {5,3,4,7};
    vector<int> v2 = {2,6};
    cout<<canSum(7, v1)<<endl;
    cout<<canSum(7, v2)<<endl;
    
    return 0;

    return 0;
}

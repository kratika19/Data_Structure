#include<bits/stdc++.h>

using namespace std;



// recursive solution
// int grid_travel(int m, int n) //int m is no of rows and int n is no of columns
// {
//      if(n==0||m==0)
//              return 0;

//      if(n==1&&m==1)
//              return 1;

//      return grid_travel(m-1, n) + grid_travel(m, n-1);
// }


// dynamic programming approach
int arr[500][500] = {0};

int
grid_travel (int m, int n)
{
    if(arr[m][n] != 0)
        return arr[m][n];
    
    if (n == 0 || m == 0)
        return 0;

    if (n == 1 && m == 1)
        return 1;
        
    arr[m][n] = grid_travel(m-1 , n) + grid_travel(m, n-1);
    
    return arr[m][n];
    
}




int
main ()
{
  cout << grid_travel (40, 60) << endl; //m is the no of rows and n is the no of columns

  return 0;
}

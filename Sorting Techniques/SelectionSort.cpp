//
// Created by krati on 12-04-2021.
//

#include <iostream>

using namespace std;

//trial algo
void selectionSort1(int A[], int n) {
    int* p;
    int* q;
   for(int i=0;i<n-1;i++)
   {
       p = q = &A[i];
       for (int j = i; j < n; ++j) {
           if(*p < *q)
           {
               q = p;
           }
           p++;
       }
       int temp = A[i];
       A[i] = *q;
       *q= temp;
   }
    cout << "Elements after sorting" << endl;
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
}

//Standard Algorithm
void selectionSort2(int A[], int n) {
    int i,j,k;
    for (int i = 0; i < n-1; i++) {
        for (j=k=i; j < n; ++j) {
            if(A[j]<A[k])
                k=j;
        }
        int temp = A[i];
        A[i] = A[k];
        A[k]= temp;
    }
    cout << "Elements after sorting" << endl;
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
}

int main() {
    int A[] = {91, 22, 89, 11, 12, 65, 41, 30, 2};
//    int A[] = {1,2,3,4,5,6,7,8,9};
//    int A[] = {8, 5, 7, 3, 2};
//    int A[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    int n = 9;
    cout << "Elements before sorting" << endl;
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl << endl;
    selectionSort1(A, n);

    cout << endl << endl;
    selectionSort2(A, n);

    return 0;
}



//**************Selection Sort Analysis*********************

//  Min time complexity = O
//  Max time complexity = O(n^2)
//  Not Adaptive
//  Stable
//  Max Swaps for n numbers = n - 1
//  Max Comparisons for n numbers = n(n-1)/2
//  Min Swaps for n numbers = 0
//  Min Comparisons for n numbers = n - 1 = O(n)



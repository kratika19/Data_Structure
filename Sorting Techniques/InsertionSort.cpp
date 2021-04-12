//
// Created by krati on 12-04-2021.
//

#include <iostream>

using namespace std;

//trial algo
void insertionSort1(int A[], int n) {
    int B[n];
    B[0] = A[0];
    for (int i = 1; i < n; ++i) {
        for (int j = i - 1; j >= 0; --j) {
            if (A[i] < B[j]) {
                B[j + 1] = B[j];
                B[j] = A[i];
            } else {
                B[j + 1] = A[i];
                break;
            }
        }
    }
    cout << "Elements after sorting" << endl;
    for (int i = 0; i < n; i++) {
        cout << B[i] << " ";
    }
}

//Standard Algorithm
void insertionSort2(int A[], int n) {
    for (int i = 1; i < n; i++) {
        int j = i - 1;
        int x = A[i];
        while (j > -1 && x < A[j]) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = x;
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
    insertionSort1(A, n);

    cout << endl << endl;
    insertionSort2(A, n);
    return 0;
}



//**************Insertion Sort Analysis*********************

//  Min time complexity = O(n)
//  Max time complexity = O(n^2)
//  Adaptive
//  Stable
//  Max Swaps for n numbers = n(n-1)/2
//  Max Comparisons for n numbers = n(n-1)/2
//  Min Swaps for n numbers = 0
//  Min Comparisons for n numbers = n - 1 = O(n)
//
// Created by krati on 12-04-2021.
//

#include <iostream>

using namespace std;

void bubbleSort(int A[], int n) {
    int flag, pass;
    pass = 0;
    for (int i = 0; i < n - 1; i++) {
        flag = 0;
        pass++;
        for (int j = 0; j < n - i - 1; j++) {
            if (A[j] > A[j + 1]) {
                int temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
                flag = 1;
            }
        }
        if (flag == 0)
            break;
    }
    cout << "Elements after sorting" << endl;
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl << endl << "No of passes = " << pass << endl;
}

int main() {
    int A[] = {91, 22, 89, 11, 2, 65, 41, 30, 2};
//    int A[] = {1,2,3,4,5,6,7,8,9};
    cout << "Elements before sorting" << endl;
    for (int i = 0; i < 9; i++) {
        cout << A[i] << " ";
    }
    cout << endl << endl;
    bubbleSort(A, 9);
    return 0;
}



//**************Bubble Sort Analysis*********************

//  Min time complexity = O
//  Max time complexity = O(n^2)
//  Adaptive
//  Stable
//  Max Swaps for n numbers = n(n-1)/2
//  Max Comparisons for n numbers = n(n-1)/2
//  Min Swaps for n numbers = 0
//  Min Comparisons for n numbers = n - 1


//
// Created by krati on 12-04-2021.
//

#include <iostream>

using namespace std;

void swap(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}

int partition(int A[], int low, int high) {
    int i = low;
    int j = high;
    int pivot = A[low];

    while (i < j) {
        do {
            i++;
        } while (A[i] <= pivot);
        do {
            j--;
        } while (A[j] > pivot);
        if (i < j)
            swap(A[i], A[j]);
    }
    swap(A[low], A[j]);
    return j;
}

void quickSort(int A[], int low, int high) {
    int j;
    if (low < high) {
        j = partition(A, low, high);
        quickSort(A, low, j);
        quickSort(A, j + 1, high);
    }
}

int main() {
    int A[] = {91, 22, 89, 11, 12, 65, 41, 30, 2, 75, INT32_MAX};
//    int A[] = {1,2,3,4,5,6,7,8,9};
//    int A[] = {8, 5, 7, 3, 2};
//    int A[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    int n = 11;
    cout << "Elements before sorting" << endl;
    for (int i = 0; i < 10; i++) {
        cout << A[i] << " ";
    }
    cout << endl << endl;

    quickSort(A, 0, 10);

    cout << "Elements after sorting" << endl;
    for (int i = 0; i < 10; i++) {
        cout << A[i] << " ";
    }


    return 0;
}



//**************Quick Sort Analysis*********************

//  Min time complexity = O(n^2)
//  Max time complexity = O(n^2)
//  Not Adaptive
//  Not Stable
//  Max Swaps for n numbers = n - 1
//  Max Comparisons for n numbers = n(n-1)/2
//  Min Swaps for n numbers = 0
//  Min Comparisons for n numbers = n(n-1)/2



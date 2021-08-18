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
    int A[] = {19, 22, 89, 11, 12, 65, 41, 30, 2, 75};
//    int A[] = {1,2,3,4,5,6,7,8,9};
//    int A[] = {8, 5, 7, 3, 2};
//    int A[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    int n = 10;
    cout << "Elements before sorting" << endl;
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl << endl;

    quickSort(A, 0, 10);

    cout << "Elements after sorting" << endl;
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
 return 0;
}



//**************Quick Sort Analysis*********************

//  here selection of element is done and then position is found.
//  selection exchange sort / partition exchange sort / pivot sort.
//  Best case (if partition is always in middle) time complexity = O(n.log(n))
//  Time complexity if list already sorted in ascending or descending manner(worst case) , can be made best case if we take middle
//  element as pivot = O(n^2)




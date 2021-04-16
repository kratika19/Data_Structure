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

void Merge(int A[], int l, int m, int h) {
    int i, j, k;
    i = l;
    j = m + 1;
    k = l;
    int C[h + 1];
    while (i <= m && j <= h) {
        if (A[i] > A[j]) {
            C[k++] = A[j++];
        } else {
            C[k++] = A[i++];
        }
    }
    for (; i <= m; ++i) {
        C[k++] = A[i];
    }
    for (; j <= h; ++j) {
        C[k++] = A[j];
    }
    for (int b = l; b <= h; b++)
        A[b] = C[b];
}

void mergeSort(int *A, int m) {
    int l, mi, h, p;
    for (p = 2; p <= m; p = p * 2) {
        for (int i = 0; i + p - 1 <= m; i = i + p) {
            l = i;
            h = i + p - 1;
            mi = (l + h) / 2;
            Merge(A, l, mi, h);

        }
    }
    if (p / 2 < m)
        Merge(A, 0, (p / 2) - 1, m - 1);
}

void insertionSort(int A[], int n) {
    for (int i = 1; i < n; i++) {
        int j = i - 1;
        int x = A[i];
        while (j > -1 && x < A[j]) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = x;
    }
}

void selectionSort(int A[], int n) {
    int i, j, k;
    for (int i = 0; i < n - 1; i++) {
        for (j = k = i; j < n; ++j) {
            if (A[j] < A[k])
                k = j;
        }
        int temp = A[i];
        A[i] = A[k];
        A[k] = temp;
    }
}

void printArr(int A[], int n) {
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
}


int main() {
    int n;
    cout << "Enter no of elements to be sorted :";
    cin >> n;

    int A[n];
    cout << "Enter the elements :";
    for (int i = 0; i < n; i++)
        cin >> A[i];
    cout << endl;
    int c;

    cout << "-----Sorting Menu-----" << endl;
    cout << "Press 1 for QuickSort" << endl;
    cout << "Press 2 for MergeSort" << endl;
    cout << "Press 3 for InsertionSort" << endl;
    cout << "Press 4 for SelectionSort" << endl;
    cout << "Make your choice :";
    cin >> c;
    cout << endl;

    switch (c) {
        case 1: {
            quickSort(A, 0, n);
            cout << "Elements after Quick Sort" << endl;
            printArr(A, n);
            break;
        }
        case 2: {
            mergeSort(A, n);
            cout << "Elements after Merge Sort" << endl;
            printArr(A, n);
            break;
        }
        case 3: {
            insertionSort(A, n);
            cout << "Elements after Insertion Sort" << endl;
            printArr(A, n);
            break;
        }
        case 4: {
            selectionSort(A, n);
            cout << "Elements after Selection Sort" << endl;
            printArr(A, n);
            break;
        }

    }
}

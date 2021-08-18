#include <iostream>

using namespace std;


void Merge(int* A, int l, int m, int h) {
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


void rMergeSort(int* A, int l, int h)
{
    if(l < h)
    {
        int mid = (l + h)/2;
        rMergeSort(A, l, mid);
        rMergeSort(A, mid+1, h);
        Merge(A, l, mid, h);
    }
}

int main() {
    int m;
    cout << "Enter size of Array :";
    cin >> m;
    cout << "Enter the elements of Array " << endl;
    int A[m];
    for (int i = 0; i < m; ++i) {
        cin >> A[i];
    }
    cout << endl;
    rMergeSort(A, 0, m);
    cout << "Elements of new merged array are" << endl;
    for (int i = 0; i < m; ++i) {
        cout << A[i] << " ";
    }
    cout << endl;
}
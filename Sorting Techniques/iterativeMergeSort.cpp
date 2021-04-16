#include <iostream>

using namespace std;


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


//new algo
void iMergeSort(int *A, int m) {
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
    iMergeSort(A, m);
    cout << "Elements of new merged array are" << endl;
    for (int i = 0; i < m; ++i) {
        cout << A[i] << " ";
    }
    cout << endl;
}
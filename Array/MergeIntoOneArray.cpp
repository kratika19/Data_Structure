#include <iostream>

using namespace std;

//new algo
void mergeArray(int A[], int l, int h, int m, int C[]) {
    int i, j, k;
    i = l;
    j = m+1;
    k = l;
    while (i <= m && j <= h) {
        if (A[i] < A[j])
            C[k++] = A[i++];
        else
            C[k++] = A[j++];
    }
    for (; i <= m; i++)
        C[k++] = A[i++];
    for (; j <= h; j++)
        C[k++] = A[j++];
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
    int C[m];
    mergeArray(A, 0, m - 1, (m - 1) / 2, C);
    cout << "Elements of new merged array are" << endl;
    for (int i = 0; i < m; ++i) {
        cout << C[i] << " ";
    }
    cout << endl;
}
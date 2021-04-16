#include <iostream>

using namespace std;

//my algo
void merge(int A[], int m, int B[], int n, int *C) {
    int s = m + n;
    int a = 0;
    int b = 0;
    int i =0;
    while(a<=m && b<=n && i<s)
    {
        if (A[a] < B[b]) {
            C[i] = A[a];
            a++;
        } else {
            C[i] = B[b];
            b++;
        }
        i++;
    }
}

//new algo
void mergeArray(int A[], int m, int B[], int n, int *C) {
    int i, j, k;
    i = j = k = 0;
    while (i <= m && j <= n) {
        if (A[i] < B[j])
            C[k++] = A[i++];
        else
            C[k++] = B[j++];
    }
    for (; i < m; i++)
        C[k++] = A[i++];
    for (; j < n; j++)
        C[k++] = B[j++];
}

int main() {
    int m, n;
    cout << "Enter size of Array 1 :";
    cin >> m;
    cout << "Enter the elements of Array 1" << endl;
    int A[m];
    for (int i = 0; i < m; ++i) {
        cin >> A[i];
    }
    cout << endl;
    cout << "Enter size of Array 2 :";
    cin >> n;
    cout << "Enter the elements of Array 2" << endl;
    int B[n];
    for (int i = 0; i < n; ++i) {
        cin >> B[i];
    }
    int *C = new int[m + n];

    merge(A, m, B, n, C);

    cout << "Elements of new merged array are" << endl;
    for (int i = 0; i < m + n; ++i) {
        cout << C[i] << " ";
    }
    cout<<endl;

    int *Ce = new int[m + n];
    mergeArray(A, m, B, n, Ce);

    cout << "Elements of new merged array are" << endl;
    for (int i = 0; i < m + n; ++i) {
        cout << Ce[i] << " ";
    }

    cout << endl;
}
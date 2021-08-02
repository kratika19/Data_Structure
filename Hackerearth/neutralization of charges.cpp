////#include<iostream>
////using namespace std;
////
////char* Neutralization(char* A )
////{
////
////}
////int main()
////{
////    int n;
////    cin>>n;
////    char* A = new char[n];
////    for(int i=0;i<n;i++)
////        cin>>A[i];
////
////
////}
//
//
//#include<iostream>
//
//using namespace std;
//
//int
//main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);
//    long long T;
//    cin >> T;
//
//    while (T--) {
//        long long N, M;
//        cin >> N >> M;
//        long long A[N];
//        long long B[M];
//
//        for (long long i = 0; i < N; i++)
//            cin >> A[i];
//
//        for (long long i = 0; i < M; i++)
//            cin >> B[i];
//
//
//        long long v1[N], v2[N];
//
//        v1[0] = v2[0] = 0;
//
//        for (int i = 1; i < N; i++) {
//            if (A[i] == 1)
//                v1[i] = 0;
//            else
//                v1[i] = -4;
//            if (A[i] == 2)
//                v2[i] = 0;
//            else
//                v2[i] = -4;
//        }
//
//        for (int i = 0; i < N; i++) {
//            if (v1[i] == -4) {
//                if (i != 1) {
//                    if (v1[i - 1] == -1)
//                        v1[i] = -1;
//                    else
//                        v1[i] = v1[i-1] + 1;
//                } else {
//                    if (A[0] == 1)
//                        v1[i] = 1;
//                    else
//                        v1[i] = -1;
//                }
//            }
//        }
//
//        if (A[N - 1] == 0)
//            v2[N - 1] = -1;
//        else {
//            if (A[N - 1] != 1)
//                v2[N - 1] = 0;
//            else
//                v2[N - 1] = -1;
//        }
//
//        for (int i = N - 2; i > 0; i--) {
//            if (v2[i] == -4) {
//                if (v2[i + 1] == -1)
//                    v2[i] = -1;
//                else
//                    v2[i] = v2[i + 1] + 1;
//            }
//        }
//
//        for (long long k = 0; k < M; k++) {
//            long long a = B[k] - 1;
//            if (v1[a] == -1 && v2[a] == -1)
//                cout << -1 << " ";
//            else if (v1[a] < v2[a] && v1[a] == -1)
//                cout << v2[a] << " ";
//            else if (v1[a] > v2[a] && v2[a] == -1)
//                cout << v1[a] << " ";
//            else if (v1[a] < v2[a])
//                cout << v1[a] << " ";
//            else
//                cout << v2[a] << " ";
//        }
//        cout<<endl;
//    }
//}
//
//
////
////
////
////
////        for (long long i = N - 1; i >= 0; i--) {
////            if (A[i] == 1) {
////                v1[i] = 0;
////                for (long long j = i - 1; j >= 0; j--) {
////                    if (A[j] == 1)
////                        v1[j] = 0;
////                    else
////                        v1[j] = -1;
////                }
////            }
////            break;
////        }
////
////        for (long long i = 0; i < N; i++) {
////            if (A[i] == 1) {
////                for (long long j = i + 1; j < N; j++) {
////                    if (A[j] == 1)
////                        v1[j] = 0;
////                    else {
////                        long long a = v1[j - 1];
////                        v1[j] = a + 1;
////                    }
////                }
////            }
////        }
////
////
////        for (long long i = 0; i < N; i++) {
////            if (A[i] == 2) {
////                v2[i] = 0;
////                for (long long j = i + 1; j < N; j++) {
////                    if (A[j] == 2)
////                        v2[i] = 0;
////                    else
////                        v2[j] = -1;
////                }
////            }
////            break;
////        }
////        for (long long i = N - 1; i >= 0; i--) {
////            if (v2[i] != -1) {
////                if (A[i] == 2)
////                    v2[i] = 0;
////                else {
////                    long long a = v2[i + 1];
////                    v2[i] = a + 1;
////                }
////            }
////        }


// C++ program to compute factorial of big numbers
#include<iostream>
using namespace std;

// Maximum number of digits in output
#define MAX 10

int multiply(int x, int res[], int res_size);

// This function finds factorial of large numbers
// and prints them
void factorial(int n)
{
    int res[MAX];

    // Initialize result
    res[0] = 1;
    int res_size = 1;

    // Apply simple factorial formula n! = 1 * 2 * 3 * 4...*n
    for (int x=2; x<=n; x++)
        res_size = multiply(x, res, res_size);

    cout << "Factorial of given number is \n";
    for (int i=res_size-1; i>=0; i--)
        cout << res[i];
}

// This function multiplies x with the number
// represented by res[].
// res_size is size of res[] or number of digits in the
// number represented by res[]. This function uses simple
// school mathematics for multiplication.
// This function may value of res_size and returns the
// new value of res_size
int multiply(int x, int res[], int res_size)
{
    int carry = 0; // Initialize carry

    // One by one multiply n with individual digits of res[]
    for (int i=0; i<res_size; i++)
    {
        int prod = res[i] * x + carry;

        // Store last digit of 'prod' in res[]
        res[i] = prod % 10;

        // Put rest in carry
        carry = prod/10;
    }

    // Put carry in res and increase result size
    while (carry)
    {
        res[res_size] = carry%10;
        carry = carry/10;
        res_size++;
    }
    return res_size;
}

// Driver program
int main()
{
    factorial(5);
    return 0;
}

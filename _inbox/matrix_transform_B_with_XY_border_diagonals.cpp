// Problem 2 - Matrix transformation (build B from sums X and Y)
// Requirements:
// - Given a square matrix A of size n x n, n > 2, read n and the elements (integers).
// - Let X be the sum of the EVEN elements in matrix A.
// - Let Y be the sum of the ODD elements in matrix A.
// - Create a new matrix B (n x n) such that:
//   * Elements in the first and last row, first and last column,
//     and on the main and secondary diagonal in B have value Y.
//   * All other elements in B have value X.
// - Print matrix B to standard output (space-separated is acceptable).
//
// Note: A cell that belongs to multiple categories (e.g., corner on diagonal)
// is still Y.

#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    vector<vector<long long>> A(n, vector<long long>(n));
    long long X = 0; // sum of even
    long long Y = 0; // sum of odd

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            long long v;
            cin >> v;
            A[i][j] = v;
            if (v % 2 == 0) X += v;
            else Y += v;
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            bool isBorder = (i == 0 || i == n - 1 || j == 0 || j == n - 1);
            bool isDiag = (i == j) || (i + j == n - 1);
            long long val = (isBorder || isDiag) ? Y : X;

            if (j) cout << ' ';
            cout << val;
        }
        cout << "\n";
    }

    return 0;
}

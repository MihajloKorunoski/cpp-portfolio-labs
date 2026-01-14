// Problem 2 - Symmetric columns and rows (matrix transform)
// Requirements:
// - Read m, n and then matrix A[m][n] from standard input (max dimension up to 100).
// - Transform the matrix in two phases:
//
// Phase 1 (by columns):
//   - For each column j from 0 to floor((n-1)/2):
//     add the element symmetric to it around the middle column: A[i][j] += A[i][n-1-j].
//   - If n is odd, then the middle column elements are doubled (since symmetric with itself).
//   - After this phase, the matrix effectively becomes m x ceil(n/2) if we keep only the left half.
//     (We will store results in-place in the first newN columns.)
//
// Phase 2 (by rows) on the reduced matrix:
//   - For each row i from 0 to floor((m-1)/2):
//     add the element symmetric to it around the middle row: A[i][j] += A[m-1-i][j] for all j in [0, newN).
//   - If m is odd, then the middle row elements are doubled.
//   - After this phase, the matrix becomes ceil(m/2) x newN (keep only the top half).
//
// - Print the final transformed matrix.
//   Elements in a row separated by TAB, rows separated by newline.

#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n;
    if (!(cin >> m >> n)) return 0;

    vector<vector<long long>> A(m, vector<long long>(n));
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            cin >> A[i][j];

    int newN = (n + 1) / 2; // ceil(n/2)
    // Phase 1: columns
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < newN; ++j) {
            int sym = n - 1 - j;
            if (j == sym) {
                A[i][j] = A[i][j] * 2;
            } else {
                A[i][j] = A[i][j] + A[i][sym];
            }
        }
    }

    int newM = (m + 1) / 2; // ceil(m/2)
    // Phase 2: rows on reduced width newN
    for (int i = 0; i < newM; ++i) {
        int symRow = m - 1 - i;
        for (int j = 0; j < newN; ++j) {
            if (i == symRow) {
                A[i][j] = A[i][j] * 2;
            } else {
                A[i][j] = A[i][j] + A[symRow][j];
            }
        }
    }

    // Print final newM x newN matrix with tabs.
    for (int i = 0; i < newM; ++i) {
        for (int j = 0; j < newN; ++j) {
            if (j) cout << '\t';
            cout << A[i][j];
        }
        cout << "\n";
    }

    return 0;
}

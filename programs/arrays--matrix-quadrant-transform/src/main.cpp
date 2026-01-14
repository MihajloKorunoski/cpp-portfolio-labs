// Problem 2 - Matrix transform by k (row) and l (column)
// Requirements:
// - From standard input read dimensions m and n of matrix A (1 < m,n < 100),
//   then read its elements.
// - Then read two integers k and l (indices of a row/column).
// - Transform A as follows:
//   * Elements ABOVE row k AND LEFT of column l are replaced with 0.
//   * Elements BELOW row k AND RIGHT of column l are replaced with the MAX element of A.
// - Print the transformed matrix.
//
// Based on the provided example, the conditions are interpreted as:
//   - "above row k" means i < k
//   - "left of column l" means j < l
//   - "below row k" means i > k
//   - "right of column l" includes column l itself => j >= l
// So:
//   if (i < k && j < l) => 0
//   if (i > k && j >= l) => maxA
//   else unchanged

#include <iostream>
#include <vector>
#include <limits>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n;
    if (!(cin >> m >> n)) return 0;

    vector<vector<long long>> a(m, vector<long long>(n));
    long long mx = numeric_limits<long long>::min();

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
            if (a[i][j] > mx) mx = a[i][j];
        }
    }

    int k, l;
    cin >> k >> l;

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i < k && j < l) a[i][j] = 0;
            else if (i > k && j >= l) a[i][j] = mx;
        }
    }

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (j) cout << ' ';
            cout << a[i][j];
        }
        cout << "\n";
    }

    return 0;
}

// Problem 2 - Prag 1: Rewrite rows based on row-sum compared to X
// Requirements:
// - From standard input read:
//   * integer X
//   * matrix dimensions M and N (integers)
//   * elements of an M x N integer matrix
// - For each row:
//   * If the sum of elements in the row is greater than X -> all elements in that row become 1
//   * If the sum is less than X -> all elements become -1
//   * If the sum equals X -> all elements become 0
// - Print the modified matrix (space-separated, rows on new lines).
//
// The example shows input where M=5, N=4.

#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long X;
    int M, N;
    if (!(cin >> X >> M >> N)) return 0;

    vector<vector<long long>> a(M, vector<long long>(N));
    for (int i = 0; i < M; ++i)
        for (int j = 0; j < N; ++j)
            cin >> a[i][j];

    for (int i = 0; i < M; ++i) {
        long long sum = 0;
        for (int j = 0; j < N; ++j) sum += a[i][j];

        long long fill = 0;
        if (sum > X) fill = 1;
        else if (sum < X) fill = -1;
        else fill = 0;

        for (int j = 0; j < N; ++j) a[i][j] = fill;
    }

    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            if (j) cout << ' ';
            cout << a[i][j];
        }
        cout << "\n";
    }
    return 0;
}

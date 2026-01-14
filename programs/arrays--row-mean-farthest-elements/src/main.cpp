// Problem 2 (Matrices -> Array)
// Requirements:
// - Read matrix dimensions m, n (m, n <= 100) from standard input.
// - Read the m x n integer elements.
// - For each row:
//   * Compute the arithmetic mean of that row.
//   * Find the element whose distance from the mean is the greatest (max |a_ij - mean|).
//   * If there are multiple such elements, take the FIRST one in that row.
// - Create an array (size m) from those chosen elements, in the same order as rows.
// - Print the array elements separated by spaces.

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n;
    if (!(cin >> m >> n)) return 0;

    vector<vector<long long>> a(m, vector<long long>(n));
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            cin >> a[i][j];

    vector<long long> out;
    out.reserve(m);

    for (int i = 0; i < m; ++i) {
        long double sum = 0.0L;
        for (int j = 0; j < n; ++j) sum += (long double)a[i][j];
        long double mean = sum / (long double)n;

        int bestJ = 0;
        long double bestDist = fabsl((long double)a[i][0] - mean);

        for (int j = 1; j < n; ++j) {
            long double dist = fabsl((long double)a[i][j] - mean);
            if (dist > bestDist) {
                bestDist = dist;
                bestJ = j;
            }
            // If equal distance, keep the first (so do nothing).
        }

        out.push_back(a[i][bestJ]);
    }

    for (int i = 0; i < (int)out.size(); ++i) {
        if (i) cout << ' ';
        cout << out[i];
    }
    cout << "\n";
    return 0;
}

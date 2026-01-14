// Problem 2 - Lines: rows/columns with >= 3 consecutive 1s
// Requirements:
// - Read M and N (max 100x100) and then elements of a matrix (only 0 and 1).
// - Determine in how many ROWS there exists at least one sequence of 3 consecutive 1s.
// - Determine in how many COLUMNS there exists at least one sequence of 3 consecutive 1s.
// - Print the total count (rows + columns) to standard output.
// Example in statement: 1 row + 1 column = 2

#include <iostream>
#include <vector>
using namespace std;

static bool hasRun3InRow(const vector<int>& row) {
    int run = 0;
    for (int v : row) {
        if (v == 1) {
            if (++run >= 3) return true;
        } else run = 0;
    }
    return false;
}

static bool hasRun3InCol(const vector<vector<int>>& a, int col) {
    int run = 0;
    for (int i = 0; i < (int)a.size(); ++i) {
        if (a[i][col] == 1) {
            if (++run >= 3) return true;
        } else run = 0;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n;
    if (!(cin >> m >> n)) return 0;

    vector<vector<int>> a(m, vector<int>(n));
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            cin >> a[i][j];

    int count = 0;

    for (int i = 0; i < m; ++i) {
        if (hasRun3InRow(a[i])) ++count;
    }
    for (int j = 0; j < n; ++j) {
        if (hasRun3InCol(a, j)) ++count;
    }

    cout << count << "\n";
    return 0;
}

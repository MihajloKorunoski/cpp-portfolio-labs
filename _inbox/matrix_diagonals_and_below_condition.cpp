// Problem 2 - Matrix condition (diagonals + below both diagonals)
// Requirements:
// - Read n and then the elements of an n x n matrix from standard input.
// - Let S1 be the sum of elements that are:
//   * on the main diagonal, OR
//   * on the secondary diagonal, OR
//   * strictly below BOTH the main and the secondary diagonal at the same time.
//     (i > j AND i + j > n - 1)
// - Let S2 be the sum of all remaining elements.
// - If S1 > S2 print: "Условот е исполнет"
//   otherwise print: "Условот не е исполнет"

#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    long long s1 = 0, s2 = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            long long x;
            cin >> x;

            bool inSet =
                (i == j) ||                      // main diagonal
                (i + j == n - 1) ||              // secondary diagonal
                (i > j && i + j > n - 1);        // below both diagonals

            if (inSet) s1 += x;
            else s2 += x;
        }
    }

    if (s1 > s2) cout << "Условот е исполнет\n";
    else         cout << "Условот не е исполнет\n";

    return 0;
}

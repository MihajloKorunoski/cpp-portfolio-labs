// Problem 1 - Recursion: Nonal complement (top 5)
// Requirements:
// - For a natural number a, b is a "nonal complement" of a iff each pair of digits
//   in the same position sums to 9.
// - Read an unknown count of integers (no more than 100) from standard input,
//   until input can no longer be interpreted as an integer.
// - For each input number, find its nonal complement.
// - Print the largest 5 complements (or fewer if < 5 numbers were entered),
//   ordered from largest to smallest.
// - Finding the nonal complement MUST be done with a separate RECURSIVE function
//   nonalComplement(int a).
// - Using global variables is FORBIDDEN.
//
// Notes:
// - For numbers whose complement would start with 0 (e.g., 987 -> 012), the
//   integer result naturally becomes shorter (12). This matches the example.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

static long long nonalComplement(long long a) {
    // Assumes a is non-negative (natural). If a could be negative, convert to abs.
    if (a < 10) return 9 - a;

    long long last = a % 10;
    long long compDigit = 9 - last;

    return nonalComplement(a / 10) * 10 + compDigit;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<long long> comps;
    comps.reserve(100);

    long long x;
    while ((int)comps.size() < 100 && (cin >> x)) {
        if (x < 0) x = -x; // defensive; task says natural numbers
        comps.push_back(nonalComplement(x));
    }

    sort(comps.begin(), comps.end(), greater<long long>());

    int k = (int)min<size_t>(5, comps.size());
    for (int i = 0; i < k; ++i) {
        if (i) cout << ' ';
        cout << comps[i];
    }
    cout << "\n";
    return 0;
}

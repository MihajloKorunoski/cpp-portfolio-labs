// Problem 3 - File with numbers: choose number with largest most significant digit
// Requirements:
// - In file "broevi.txt" there are multiple lines.
// - Each line starts with an integer N (N >= 1) indicating how many numbers follow on that line.
// - For each line, print to standard output the number whose MOST SIGNIFICANT digit is the largest.
// - Reading stops when N == 0 is read.
// - Words in statement: "Читањето на броеви завршува кога ќе се прочита 0."
// - If there is a tie (same most significant digit), keep the first encountered number.
// - If the file cannot be opened, fall back to reading the same format from standard input.
//
// Notes:
// - Most significant digit of a negative number is computed using its absolute value,
//   but the original number is printed (defensive).

#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

static int mostSignificantDigit(long long x) {
    if (x < 0) x = llabs(x);
    if (x == 0) return 0;
    while (x >= 10) x /= 10;
    return (int)x;
}

static void solve(istream &in) {
    long long N;
    while (in >> N) {
        if (N == 0) break;

        long long bestNum = 0;
        int bestMSD = -1;

        for (long long i = 0; i < N; ++i) {
            long long v;
            in >> v;
            int msd = mostSignificantDigit(v);
            if (msd > bestMSD) {
                bestMSD = msd;
                bestNum = v;
            }
        }
        cout << bestNum << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream fin("broevi.txt");
    if (fin.is_open()) solve(fin);
    else solve(cin);

    return 0;
}

// Problem 3 - Longest sequence of consecutive digits from input.txt
// Requirements:
// - Given a file "input.txt" containing characters (may include digits and non-digits).
// - Find the longest sequence of consecutive characters that are digits (0-9).
// - The sequence must NOT span multiple lines (must be within a single line).
// - Print on standard output:
//   * First: the length of that longest digit sequence
//   * Second: the sequence itself
// - If there are multiple sequences with the same maximum length, print the first one found.
// - If the file cannot be opened, fall back to reading from standard input.
//
// Notes:
// - Lines are up to 100 characters (as implied by the tasks style).
// - If a line contains no digits, it contributes nothing.

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;

static void solve(istream &in) {
    string line;
    string bestSeq = "";
    int bestLen = 0;

    while (getline(in, line)) {
        int i = 0;
        while (i < (int)line.size()) {
            if (isdigit((unsigned char)line[i])) {
                int start = i;
                while (i < (int)line.size() && isdigit((unsigned char)line[i])) ++i;
                int len = i - start;
                if (len > bestLen) {
                    bestLen = len;
                    bestSeq = line.substr(start, len);
                }
            } else {
                ++i;
            }
        }
    }

    cout << bestLen << "\n";
    cout << bestSeq << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream fin("input.txt");
    if (fin.is_open()) solve(fin);
    else solve(cin);

    return 0;
}

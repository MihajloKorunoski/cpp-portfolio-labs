// Problem 1 - Recursion: tapiserya(n) pattern with '*' and '#'
// Requirements:
// - Write a recursive function tapiserya(n) that for given n prints a "tapiserya"
//   using the characters '*' and '#'.
// - You MAY use helper functions, but you MUST NOT use any repetition statements
//   (no for / while / do-while).
// - Input: integer n (as shown in examples).
// - Output: n lines, where line i (0-based) has length n-i, filled with alternating
//   '*' and '#'. The starting character alternates per row.
//   From examples:
//     n=4 prints:
//       *#*#
//       #*#
//       *#
//       #
//     n=3 prints:
//       #*#
//       *#
//       #
//
// This implementation matches the examples with the rule:
// - Row r starts with '*' if (n + r) is even, otherwise '#'.

#include <iostream>
using namespace std;

static void printRowRec(int pos, int len, char ch) {
    if (pos >= len) return;
    cout << ch;
    char next = (ch == '*') ? '#' : '*';
    printRowRec(pos + 1, len, next);
}

static void tapiseryaRowsRec(int n, int r) {
    if (r >= n) return;

    int len = n - r;
    char start = ((n + r) % 2 == 0) ? '*' : '#';
    printRowRec(0, len, start);
    cout << "\n";

    tapiseryaRowsRec(n, r + 1);
}

static void tapiserya(int n) {
    tapiseryaRowsRec(n, 0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    if (n < 0) n = 0;
    tapiserya(n);

    return 0;
}

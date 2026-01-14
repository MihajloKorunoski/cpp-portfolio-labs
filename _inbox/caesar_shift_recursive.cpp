// Problem 1 - Caesar (recursive transformation)
// Requirements:
// - From standard input read:
//   * N: number of strings
//   * X: shift amount
// - Then read N strings (each not longer than 80 characters).
// - For each string, replace every letter:
//   * lowercase a-z: shift forward by X (cyclic, wrap around)
//   * uppercase A-Z: shift forward by X (cyclic, wrap around)
//   Non-letters stay unchanged.
// - Print each transformed string on its own line.
// - The transformation MUST be implemented with a separate recursive function.
//
// Example: "Welcome" with X=5 -> "Bjqhtrj"

#include <iostream>
#include <string>
using namespace std;

static char shiftChar(char c, int x) {
    x %= 26;
    if (x < 0) x += 26;

    if (c >= 'a' && c <= 'z') {
        int pos = c - 'a';
        return char('a' + (pos + x) % 26);
    }
    if (c >= 'A' && c <= 'Z') {
        int pos = c - 'A';
        return char('A' + (pos + x) % 26);
    }
    return c;
}

static void transformRec(string &s, int idx, int x) {
    if (idx >= (int)s.size()) return;
    s[idx] = shiftChar(s[idx], x);
    transformRec(s, idx + 1, x);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, X;
    if (!(cin >> N >> X)) return 0;

    // Consume the rest of the line before getline.
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int i = 0; i < N; ++i) {
        string s;
        getline(cin, s);
        // Some judges might provide strings without spaces via >>;
        // but getline still works (reads the line).
        if ((int)s.size() > 80) s.resize(80);

        transformRec(s, 0, X);
        cout << s << "\n";
    }
    return 0;
}

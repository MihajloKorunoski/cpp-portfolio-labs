// Problem 3 - File vlezna.txt: print longest line that is only letters OR only digits
// Requirements:
// - In file "vlezna.txt" there are strings (each on its own line) containing letters,
//   digits, and special characters. Each line length <= 80.
// - Print the line that has the largest number of characters AND contains:
//   * only letters (A-Z, a-z), OR
//   * only digits (0-9)
// - If no such line exists, print: Nema!
// - If two or more lines satisfy the condition with the same maximum length,
//   print the FIRST one.
// - Read from "vlezna.txt". If it can't be opened, fall back to stdin.

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;

static bool allLetters(const string &s) {
    if (s.empty()) return false;
    for (char c : s) {
        if (!isalpha((unsigned char)c)) return false;
    }
    return true;
}

static bool allDigits(const string &s) {
    if (s.empty()) return false;
    for (char c : s) {
        if (!isdigit((unsigned char)c)) return false;
    }
    return true;
}

static void solve(istream &in) {
    string line;
    string best = "";
    int bestLen = -1;

    while (getline(in, line)) {
        if ((int)line.size() > 80) line.resize(80);

        if (allLetters(line) || allDigits(line)) {
            int len = (int)line.size();
            if (len > bestLen) {
                bestLen = len;
                best = line;
            }
        }
    }

    if (bestLen == -1) cout << "Nema!\n";
    else cout << best << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream fin("vlezna.txt");
    if (fin.is_open()) solve(fin);
    else solve(cin);

    return 0;
}

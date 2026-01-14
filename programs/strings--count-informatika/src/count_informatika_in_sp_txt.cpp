// Problem 3 - Count "Informatika" in file sp.txt
// Requirements:
// - Read text from the file "sp.txt".
// - Words in the file consist ONLY of letters, have length <= 50,
//   and are separated by any number of special characters and whitespace.
// - Print the number of occurrences of the word "Informatika".
// Notes:
// - This solution matches the word exactly as "Informatika" (case-sensitive).
// - If the file cannot be opened, it falls back to reading from standard input.

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

static bool isLetter(char c) {
    return std::isalpha(static_cast<unsigned char>(c)) != 0;
}

static long long countInStream(istream &in) {
    const string target = "Informatika";
    string cur;
    cur.reserve(64);

    long long cnt = 0;
    char c;
    while (in.get(c)) {
        if (isLetter(c)) {
            if (cur.size() < 50) cur.push_back(c);
            else {
                // If a word is longer than 50 (shouldn't happen), keep reading letters but cap.
            }
        } else {
            if (!cur.empty()) {
                if (cur == target) ++cnt;
                cur.clear();
            }
        }
    }
    if (!cur.empty() && cur == target) ++cnt;

    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream fin("sp.txt");
    if (fin.is_open()) {
        cout << countInStream(fin) << "\n";
    } else {
        cout << countInStream(cin) << "\n";
    }
    return 0;
}

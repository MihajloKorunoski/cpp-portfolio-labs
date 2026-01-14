// Problem 3 - Substring between first two punctuation marks (file vlez.txt)
// Requirements:
// - For each line in the input file "vlez.txt", print a substring from that line to standard output.
// - The substring is formed by taking ALL characters that are BETWEEN the FIRST TWO punctuation symbols in the line.
// - Punctuation symbols are: ( . , ! ? - : ; )
// - Each line has maximum length 100 characters.
// - It is guaranteed that every line contains at least two punctuation symbols.
// - Print one extracted substring per line, each on its own line.
// Notes:
// - Characters between punctuation marks are printed exactly as-is (including spaces).
// - If the file cannot be opened, fall back to reading from standard input line-by-line.

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

static bool isPunct(char c) {
    switch (c) {
        case '.': case ',': case '!': case '?': case '-': case ':': case ';':
            return true;
        default:
            return false;
    }
}

static void process(istream &in) {
    string line;
    while (std::getline(in, line)) {
        if ((int)line.size() > 100) line.resize(100);

        int first = -1, second = -1;
        for (int i = 0; i < (int)line.size(); ++i) {
            if (isPunct(line[i])) {
                if (first == -1) first = i;
                else { second = i; break; }
            }
        }

        // Guaranteed at least two punctuation marks.
        if (first != -1 && second != -1 && second > first + 1) {
            cout << line.substr(first + 1, second - first - 1) << "\n";
        } else {
            // Between them is empty.
            cout << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream fin("vlez.txt");
    if (fin.is_open()) process(fin);
    else process(cin);

    return 0;
}

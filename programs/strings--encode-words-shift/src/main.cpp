// Problem 3 (File I/O + Encoding)
// Requirements:
// - A file named "input.txt" exists; each line contains one word (max 20 letters).
// - Read all words from input.txt.
// - For each word, encode it and print the encoded word to standard output.
// Encoding rules:
// 1) Each letter is replaced with the next letter in the alphabet.
//    - 'a'->'b', ..., 'y'->'z', 'z'->'a'
//    - 'A'->'B', ..., 'Y'->'Z', 'Z'->'A'
// 2) After step (1), convert all letters to lowercase.
// Example: "Hello" -> "ifmmp", "two" -> "uxp", "Zero" -> "afsp"

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

static char shiftLetter(char c) {
    if (c >= 'a' && c <= 'y') return (char)(c + 1);
    if (c == 'z') return 'a';
    if (c >= 'A' && c <= 'Y') return (char)(c + 1);
    if (c == 'Z') return 'A';
    // If something unexpected appears, leave it unchanged.
    return c;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream fin("input.txt");
    if (!fin.is_open()) {
        // If the platform runs with stdin instead, fall back gracefully:
        // read from stdin and do the same transformation.
        string word;
        while (cin >> word) {
            for (char &ch : word) {
                ch = (char)tolower((unsigned char)shiftLetter(ch));
            }
            cout << word << "\n";
        }
        return 0;
    }

    string word;
    while (fin >> word) {
        for (char &ch : word) {
            ch = (char)tolower((unsigned char)shiftLetter(ch));
        }
        cout << word << "\n";
    }

    return 0;
}

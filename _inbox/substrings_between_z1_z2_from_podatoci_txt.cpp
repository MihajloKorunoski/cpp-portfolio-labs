// Problem 3 - Podatoci: print substring between z1 and z2 from each line in podatoci.txt
// Requirements:
// - File "podatoci.txt" contains lines of text (each up to 80 characters).
// - From standard input read two characters z1 and z2.
// - For each line in podatoci.txt, print the substring consisting of characters
//   that are BETWEEN z1 and z2 (excluding z1 and z2), each substring on its own line.
// - It is guaranteed that each line contains z1 and z2 exactly once,
//   z1 always appears BEFORE z2, and there is at least one character between them.
// - If the file cannot be opened, fall back to reading lines from standard input
//   after z1 and z2 are read.

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

static void process(istream &in, char z1, char z2) {
    string line;
    while (getline(in, line)) {
        if ((int)line.size() > 80) line.resize(80);

        size_t p1 = line.find(z1);
        size_t p2 = line.find(z2);

        if (p1 != string::npos && p2 != string::npos && p1 < p2 && p2 > p1 + 1) {
            cout << line.substr(p1 + 1, p2 - p1 - 1) << "\n";
        } else {
            // Shouldn't happen given guarantees, but keep output stable.
            cout << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    char z1, z2;
    if (!(cin >> z1 >> z2)) return 0;

    // consume remainder of line before getline if fallback to stdin later
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    ifstream fin("podatoci.txt");
    if (fin.is_open()) process(fin, z1, z2);
    else process(cin, z1, z2);

    return 0;
}

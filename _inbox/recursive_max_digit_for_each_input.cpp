// Problem 1 - Recursion 1: maximum digit of an integer
// Requirements:
// - Write a RECURSIVE function to find the maximum digit of a given integer.
// - From standard input read an unknown number of integers until input is not a number.
// - For each read integer, print its maximum digit on a separate line.
// - Using global variables is FORBIDDEN.
// Notes:
// - For negative numbers, digits are considered from the absolute value.

#include <iostream>
#include <cstdlib>
using namespace std;

static int maxDigitRec(long long x) {
    if (x < 0) x = llabs(x);
    if (x < 10) return (int)x;

    int last = (int)(x % 10);
    int restMax = maxDigitRec(x / 10);
    return (last > restMax) ? last : restMax;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long x;
    while (cin >> x) {
        cout << maxDigitRec(x) << "\n";
    }
    return 0;
}

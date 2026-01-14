// Problem 1 - Transform array: product of ODD digits (recursion)
// Requirements:
// - Read integer n (0 < n < 100), then read n positive integers (array A).
// - Transform A so each element becomes the product of the ODD digits in the number.
//   * If the number has no odd digits, the transformed value is 1.
//   * Digit 0 is considered EVEN (so it is NOT included here).
// - Computing the product of odd digits MUST be done using a RECURSIVE function.
// - Print the transformed array to standard output (space-separated).
//
// Example:
// Input: 4   2 13 1225 2202
// Output: 1 3 5 1

#include <iostream>
using namespace std;

static unsigned long long oddDigitsProductRec(unsigned long long x, bool &foundOdd) {
    if (x == 0) return 1;
    unsigned int digit = (unsigned int)(x % 10ULL);
    unsigned long long prod = oddDigitsProductRec(x / 10ULL, foundOdd);

    if (digit % 2 == 1) {
        foundOdd = true;
        return prod * (unsigned long long)digit;
    }
    return prod;
}

static unsigned long long productOddDigits(unsigned long long x) {
    if (x == 0) return 1; // number 0 has no odd digits
    bool foundOdd = false;
    unsigned long long prod = oddDigitsProductRec(x, foundOdd);
    return foundOdd ? prod : 1ULL;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    if (n < 0) n = 0;
    if (n > 99) n = 99;

    for (int i = 0; i < n; ++i) {
        unsigned long long x;
        cin >> x;
        unsigned long long t = productOddDigits(x);
        if (i) cout << ' ';
        cout << t;
    }
    cout << "\n";
    return 0;
}

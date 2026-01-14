// Problem 1 - Product of even digits (recursion)
// Requirements:
// - Read an array A of natural numbers (0 <= i < 100).
// - The size n and the elements are read from standard input.
// - Transform the array so each element becomes the product of the even digits in that number.
//   * Digit 0 is considered even.
//   * If a number has NO even digits, its product is 1.
// - The computation of the product of even digits MUST be done using a recursive function.
// - Print the transformed array to standard output (space-separated).

#include <iostream>
using namespace std;

static unsigned long long evenDigitsProductRec(unsigned long long x, bool &foundEven) {
    if (x == 0) return 1; // end of recursion for multi-digit numbers
    unsigned int digit = (unsigned int)(x % 10ULL);

    unsigned long long prod = evenDigitsProductRec(x / 10ULL, foundEven);

    if (digit % 2 == 0) {
        foundEven = true;
        return prod * (unsigned long long)digit;
    }
    return prod;
}

static unsigned long long productEvenDigits(unsigned long long x) {
    // Special case: number is 0 => it has an even digit (0), product is 0.
    if (x == 0) return 0;

    bool foundEven = false;
    unsigned long long prod = evenDigitsProductRec(x, foundEven);
    return foundEven ? prod : 1ULL;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    if (n < 0) n = 0;
    if (n > 100) n = 100;

    for (int i = 0; i < n; ++i) {
        unsigned long long x;
        cin >> x;
        unsigned long long transformed = productEvenDigits(x);
        if (i) cout << ' ';
        cout << transformed;
    }
    cout << "\n";
    return 0;
}

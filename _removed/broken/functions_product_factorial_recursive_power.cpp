// Problem 1 (Functions)
// Requirements:
// - Read natural numbers y, a, b from standard input.
// - Compute: p = Π_{i=a}^{b} ( i! + y^i )
// - Factorial MUST be implemented as a separate (non-recursive) function.
// - Power y^i MUST be implemented as a recursive function.
// - Print p to standard output.
//
// Notes:
// - Uses big integers (boost::multiprecision::cpp_int) to avoid overflow for typical test ranges.

#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>

using boost::multiprecision::cpp_int;
using namespace std;

cpp_int factorial(unsigned int n) {
    cpp_int f = 1;
    for (unsigned int i = 2; i <= n; ++i) f *= i;
    return f;
}

// Recursive power using exponentiation by squaring.
cpp_int powRec(const cpp_int& base, unsigned int exp) {
    if (exp == 0) return 1;
    if (exp == 1) return base;
    cpp_int half = powRec(base, exp / 2);
    cpp_int res = half * half;
    if (exp % 2 == 1) res *= base;
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    unsigned int y, a, b;
    if (!(cin >> y >> a >> b)) return 0;

    if (a > b) {
        // If input is reversed, swap (defensive; not usually needed).
        swap(a, b);
    }

    cpp_int p = 1;
    for (unsigned int i = a; i <= b; ++i) {
        cpp_int term = factorial(i) + powRec(cpp_int(y), i);
        p *= term;
    }

    cout << p << "\n";
    return 0;
}

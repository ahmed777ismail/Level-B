#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

// Function to check if a number is lovely (not divisible by any a^2 where a > 1)
bool isLovely(long long x) {
    for (long long a = 2; a * a <= x; ++a) {
        if (x % (a * a) == 0) {
            return false;
        }
    }
    return true;
}

long long largestLovelyNumber(long long n) {
    vector<long long> divisors;

    // Find all divisors of n
    for (long long i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            divisors.push_back(i);
            if (i != n / i) {
                divisors.push_back(n / i);
            }
        }
    }

    // Sort divisors in descending order
    sort(divisors.rbegin(), divisors.rend());

    // Find the largest lovely divisor
    for (long long d : divisors) {
        if (isLovely(d)) {
            return d;
        }
    }

    return 1; // This should never be reached
}

int main() {
    long long n;
    cin >> n;
    cout << largestLovelyNumber(n) << endl;
    return 0;
}

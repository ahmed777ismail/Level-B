#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n), sorted_arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sorted_arr = arr;
    sort(sorted_arr.begin(), sorted_arr.end());

    // If already sorted, return "yes" and "1 1"
    if (arr == sorted_arr) {
        cout << "yes\n1 1\n";
        return 0;
    }

    int l = 0, r = n - 1;

    // Find the leftmost index where arr differs from sorted_arr
    while (l < n && arr[l] == sorted_arr[l]) {
        l++;
    }

    // Find the rightmost index where arr differs from sorted_arr
    while (r > l && arr[r] == sorted_arr[r]) {
        r--;
    }

    // Reverse the found segment
    reverse(arr.begin() + l, arr.begin() + r + 1);

    if (arr == sorted_arr) {
        cout << "yes\n" << l + 1 << " " << r + 1 << "\n"; // Convert to 1-based index
    }
    else {
        cout << "no\n";
    }

    return 0;
}

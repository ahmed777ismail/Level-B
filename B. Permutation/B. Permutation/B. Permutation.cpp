#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    unordered_set<int> uniqueElements;
    int validCount = 0;

    for (int num : a) {
        if (num >= 1 && num <= n && uniqueElements.find(num) == uniqueElements.end()) {
            uniqueElements.insert(num);
            validCount++;
        }
    }

    int changesNeeded = n - validCount;
    cout << changesNeeded << endl;

    return 0;
}
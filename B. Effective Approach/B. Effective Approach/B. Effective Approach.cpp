#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    int n, m;
    cin >> n;

    unordered_map<int, int> indexMap;
    for (int i = 1; i <= n; i++) {
        int val;
        cin >> val;
        indexMap[val] = i; // Store position (1-based index)
    }

    cin >> m;
    long long vasya_count = 0, petya_count = 0;

    for (int i = 0; i < m; i++) {
        int query;
        cin >> query;

        int pos = indexMap[query]; // Get the position of the queried element
        vasya_count += pos;        // Comparisons needed for Vasya
        petya_count += (n - pos + 1); // Comparisons needed for Petya
    }

    cout << vasya_count << " " << petya_count << endl;

    return 0;
}

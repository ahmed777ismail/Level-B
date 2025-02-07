#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxWateredSections(const vector<int>& heights) {
    int n = heights.size();
    int maxWatered = 0;

    for (int i = 0; i < n; i++) {
        int count = 1; // Start with the current section

        // Spread to the left
        for (int j = i - 1; j >= 0; j--) {
            if (heights[j] <= heights[j + 1]) count++;
            else break;
        }

        // Spread to the right
        for (int j = i + 1; j < n; j++) {
            if (heights[j] <= heights[j - 1]) count++;
            else break;
        }

        maxWatered = max(maxWatered, count);
    }

    return maxWatered;
}

int main() {
    int n;
    cin >> n;
    vector<int> heights(n);

    for (int i = 0; i < n; i++) {
        cin >> heights[i];
    }

    cout << maxWateredSections(heights) << endl;

    return 0;
}

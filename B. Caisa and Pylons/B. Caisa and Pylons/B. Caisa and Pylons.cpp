#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> h(n);
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }

    int energy = 0;
    int max_deficit = 0;
    int prev_height = 0; // Height of pylon 0

    for (int i = 0; i < n; ++i) {
        int delta = prev_height - h[i];
        energy += delta;
        if (energy < 0) {
            max_deficit = max(max_deficit, -energy);
        }
        prev_height = h[i];
    }

    cout << max_deficit << endl;
    return 0;
}
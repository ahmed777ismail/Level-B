#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, f;
    cin >> n >> f;

    vector<pair<int, int>> days(n);
    vector<int> extra_products(n);
    long long total_sold = 0;

    for (int i = 0; i < n; i++) {
        int k, l;
        cin >> k >> l;
        days[i] = { k, l };

        // Calculate the actual sales for the day
        total_sold += min(k, l);

        // Calculate extra possible sales if the day is chosen for sell-out
        extra_products[i] = min(2 * k, l) - min(k, l);
    }

    // Sort extra_products in descending order to maximize additional sales
    sort(extra_products.rbegin(), extra_products.rend());

    // Select the top f days to double the sales
    for (int i = 0; i < f; i++) {
        total_sold += extra_products[i];
    }

    cout << total_sold << endl;
    return 0;
}

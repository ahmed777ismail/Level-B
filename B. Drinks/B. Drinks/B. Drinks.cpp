#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> percentages(n);

    double sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> percentages[i];
        sum += percentages[i];
    }

    cout << fixed << setprecision(12) << (sum / n) << endl;

    return 0;
}

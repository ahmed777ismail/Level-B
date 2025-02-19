#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int q;
    cin >> q;

    unordered_map<string, string> originalHandle; // Maps initial username -> final username
    unordered_map<string, string> currentHandle;  // Maps current username -> original username

    for (int i = 0; i < q; i++) {
        string oldHandle, newHandle;
        cin >> oldHandle >> newHandle;

        string original = oldHandle;

        // If the oldHandle was previously changed, find its original
        if (currentHandle.find(oldHandle) != currentHandle.end()) {
            original = currentHandle[oldHandle];
            currentHandle.erase(oldHandle); // Remove old reference
        }

        // Update mappings
        originalHandle[original] = newHandle;
        currentHandle[newHandle] = original;
    }

    // Print the number of unique users who changed their handles
    cout << originalHandle.size() << endl;

    // Print the mappings
    for (const auto& entry : originalHandle) {
        cout << entry.first << " " << entry.second << endl;
    }

    return 0;
}

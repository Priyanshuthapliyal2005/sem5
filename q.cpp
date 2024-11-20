#include <bits/stdc++.h>
using namespace std;

int solve() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Initialize the minimum operations as a large value
    int min_operations = INT_MAX;

    for (int i = 0; i < n; i++) {
        int mod = arr[i] % k;
        if (mod == 0) {
            // If any element is already divisible by k, return 0
            return 0;
        }
        // Calculate operations needed to make arr[i] divisible by k
        int operations = k - mod;
        min_operations = min(min_operations, operations);
    }

    return min_operations;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cout << solve() << endl;
    }
    return 0;
}

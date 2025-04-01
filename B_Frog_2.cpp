#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> h(n);      
    vector<int> dp(n, INT_MAX);  

    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }

    dp[0] = 0;  // Base case: no cost to start at the first stone

    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= k; j++) {
            if (i - j >= 0) {
                dp[i] = min(dp[i], dp[i - j] + abs(h[i] - h[i - j]));
            }
        }
    }

    cout << dp[n - 1] << endl;  // Minimum cost to reach the last stone
    return 0;
}

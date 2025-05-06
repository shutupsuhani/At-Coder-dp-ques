#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    // dp[l][r] = max score difference current player can achieve on subarray [l...r]
    vector<vector<long long>> dp(N, vector<long long>(N, 0));

    // Base case: when l == r, only one element to pick
    for (int i = 0; i < N; ++i) {
        dp[i][i] = a[i];
    }

    // Fill dp for increasing lengths of subarrays
    for (int len = 2; len <= N; ++len) {
        for (int l = 0; l + len - 1 < N; ++l) {
            int r = l + len - 1;
            dp[l][r] = max(
                a[l] - dp[l + 1][r],  // pick left
                a[r] - dp[l][r - 1]   // pick right
            );
        }
    }

    cout << dp[0][N - 1] << endl;
    return 0;
}

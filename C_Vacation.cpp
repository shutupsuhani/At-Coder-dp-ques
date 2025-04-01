#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<vector<int>> dp(N, vector<int>(3, 0));
    vector<vector<int>> happiness(N, vector<int>(3));

    // Input happiness values
    for (int i = 0; i < N; i++) {
        cin >> happiness[i][0] >> happiness[i][1] >> happiness[i][2];
    }

    // Base case: First day's happiness values
    dp[0][0] = happiness[0][0];
    dp[0][1] = happiness[0][1];
    dp[0][2] = happiness[0][2];

    // DP transition
    for (int i = 1; i < N; i++) {
        dp[i][0] = max(dp[i-1][1], dp[i-1][2]) + happiness[i][0];
        dp[i][1] = max(dp[i-1][0], dp[i-1][2]) + happiness[i][1];
        dp[i][2] = max(dp[i-1][0], dp[i-1][1]) + happiness[i][2];
    }

    // Answer is the max happiness on the last day
    cout << max({dp[N-1][0], dp[N-1][1], dp[N-1][2]}) << endl;

    return 0;
}

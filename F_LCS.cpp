#include <bits/stdc++.h>
using namespace std;

string findLCS(string s, string t) {
    int m = s.size(), n = t.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Fill DP table
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s[i - 1] == t[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // Backtrack to reconstruct the LCS string
    int i = m, j = n;
    string lcs = "";
    while (i > 0 && j > 0) {
        if (s[i - 1] == t[j - 1]) {
            lcs += s[i - 1];  // Include this character in LCS
            i--; j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;  // Move up
        } else {
            j--;  // Move left
        }
    }

    reverse(lcs.begin(), lcs.end());  // Reverse to get correct order
    return lcs;
}

int main() {
    string s, t;
    cin >> s >> t;
    cout << findLCS(s, t) << endl;
    return 0;
}

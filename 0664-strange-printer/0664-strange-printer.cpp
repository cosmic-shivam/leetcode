class Solution {
public:
    int strangePrinter(string s) {
        //copied try once you learn dp
        int n = s.size();
    if (n == 0) return 0;

    vector<vector<int>> dp(n, vector<int>(n, n));

    // Base case: single character substrings
    for (int i = 0; i < n; ++i) {
        dp[i][i] = 1;
    }

    // Fill the dp table
    for (int length = 2; length <= n; ++length) {
        for (int i = 0; i <= n - length; ++i) {
            int j = i + length - 1;
            if (s[i] == s[j]) {
                dp[i][j] = dp[i][j - 1];
            }
            for (int k = i; k < j; ++k) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
            }
        }
    }

    return dp[0][n - 1];
        
    }
};
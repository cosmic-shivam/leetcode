class Solution {
public:
    int stoneGameII(vector<int>& piles) {
    int n = piles.size();
    vector<vector<int>> dp(n, vector<int>(n+1, 0));
    vector<int> suffixSum(n, 0);
    
    suffixSum[n-1] = piles[n-1];
    for (int i = n-2; i >= 0; i--) {
        suffixSum[i] = suffixSum[i+1] + piles[i];
    }
    
    for (int i = n-1; i >= 0; i--) {
        for (int M = 1; M <= n; M++) {
            for (int X = 1; X <= 2 * M && i + X <= n; X++) {
                // Ensure that i + X is within bounds
                if (i + X < n) {
                    dp[i][M] = max(dp[i][M], suffixSum[i] - dp[i + X][min(max(M, X), n)]);
                } else {
                    // If i + X exceeds bounds, player can take all remaining stones
                    dp[i][M] = max(dp[i][M], suffixSum[i]);
                }
            }
        }
    }
    
    return dp[0][1];
}

};
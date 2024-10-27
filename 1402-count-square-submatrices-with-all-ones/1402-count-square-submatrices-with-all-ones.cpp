class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
         int m = matrix.size();
    int n = matrix[0].size();
    
    // Initialize a dp matrix with the same dimensions as the input matrix
    vector<vector<int>> dp(m, vector<int>(n, 0));
    int totalSquares = 0;
    
    // Fill the dp matrix
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] == 1) {
                // If we're on the first row or first column, the largest square is itself
                if (i == 0 || j == 0) {
                    dp[i][j] = 1;
                } else {
                    // Update dp[i][j] based on the minimum of top, left, and top-left
                    dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
                }
                // Accumulate the count of squares
                totalSquares += dp[i][j];
            }
        }
    }
    
    return totalSquares;
        
    }
};
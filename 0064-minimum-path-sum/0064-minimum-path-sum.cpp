class Solution {
public:

    int cal(int m,int n,vector<vector<int>>& grid,vector<vector<int>>& dp)
    {
        if(m==0 && n==0)return grid[0][0];
        if(m<0 || n<0)return INT_MAX;

        if(dp[m][n]!=-1)return dp[m][n];

        int up=cal(m-1,n,grid,dp);
        int left=cal(m,n-1,grid,dp);

         if (up != INT_MAX) up += grid[m][n];
         if (left != INT_MAX) left += grid[m][n];

        return dp[m][n]=min(up,left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));

        return cal(m-1,n-1,grid,dp);
        
    }
};
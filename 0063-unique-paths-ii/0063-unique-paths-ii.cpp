class Solution {
public:


    int cal(int m,int n,vector<vector<int>>&dp,vector<vector<int>>& obs)
    {
        if(m==0 && n==0)return 1;
        if(m<0 || n<0)return 0;
        if(dp[m][n]!=-1)return dp[m][n];

            if(obs[m][n]==1)return dp[m][n] = 0;;
            int up=cal(m-1,n,dp,obs);
            int left=cal(m,n-1,dp,obs);  
            return dp[m][n]=up+left;

    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
         //edge case   if starting or ending has obstacle it's imposiible to calculate hence return 0
         if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1) return 0;
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return cal(m-1,n-1,dp,obstacleGrid);
        
    }
};
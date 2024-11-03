class Solution {
public:

    int helper(int n,int m,vector<vector<int>>& triangle,vector<vector<int>>&dp,int i)
    {

        if(i==n-1)return triangle[i][m];

        if(dp[i][m]!=-1)return dp[i][m];

        int d=triangle[i][m]+helper(n,m,triangle,dp,i+1);
        int dg=triangle[i][m]+helper(n,m+1,triangle,dp,i+1);

        return dp[i][m]=min(d,dg);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        // int m=triangle[0].size();

        vector<vector<int>>dp(n,vector<int>(n,-1));

        return helper(n,0,triangle,dp,0);
        
    }
};
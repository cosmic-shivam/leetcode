class Solution {
public:
    int cal(int n,vector<int>&dp)
    {
        if(n<=1)return 1;
        if(dp[n]!=-1)return dp[n];


        return dp[n]=cal(n-1,dp)+cal(n-2,dp);

        
    }
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        return cal(n,dp);
        
    }
};
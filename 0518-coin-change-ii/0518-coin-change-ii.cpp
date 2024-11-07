class Solution {
public:

    int helper(int n,int amount,vector<int>& coins,vector<vector<int>>&dp)
    {
        if(amount==0)return 1;
        if (n < 0) return 0;
        if(dp[n][amount]!=-1)return dp[n][amount];

        int take=0;
        if(amount>=coins[n])
        {
            take=helper(n,amount-coins[n],coins,dp);
        }
        int nottake=helper(n-1,amount,coins,dp);

        return dp[n][amount]=take+nottake;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        sort(coins.begin(),coins.end());
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return helper(n-1,amount,coins,dp);
        
    }
};
class Solution {
public:

    int helper(int n,int amount,vector<int>& coins,vector<vector<int>>&dp)
    {
        if(amount==0)return 0;

        if (n < 0) return 1e7;


        if(dp[n][amount]!=-1)return dp[n][amount];
        int take=1e7;
        if(amount>=coins[n])
        {
            take=1+helper(n,amount-coins[n],coins,dp);
        }
        int nottake=helper(n-1,amount,coins,dp);

        return dp[n][amount]=min(take,nottake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        sort(coins.begin(),coins.end());
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int result = helper(n - 1, amount, coins, dp);

        return result >= 1e7 ? -1 : result;
        
    }
};
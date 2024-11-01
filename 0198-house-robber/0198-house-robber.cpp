class Solution {
public:

    int cal(int n,vector<int>&nums,vector<int>&dp)
    {
        if(n==0)return nums[n];

        if(n<0)return 0;

        if(dp[n]!=-1)return dp[n];

        int pick=nums[n]+cal(n-2,nums,dp);

        int notpick=0+cal(n-1,nums,dp);

        return dp[n]=max(pick,notpick);

    }

    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);

        return cal(n-1,nums,dp);
        
    }
};
class Solution {
public:

    int helper(int n,int target,vector<int>& nums,vector<vector<int>>&dp)
    {
        if(n==0)
        {
            if(target==0 && nums[n]==0)return 2;
            if(target==0 || target==nums[n] )return 1;
            return 0;
        }
        if(dp[n][target]!=-1)return dp[n][target];
        int take=0;
        if(target>=nums[n])
        {
            take=helper(n-1,target-nums[n],nums,dp);
        }
        int nottake=helper(n-1,target,nums,dp);
        return dp[n][target]=take+nottake;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int total=accumulate(nums.begin(),nums.end(),0);
        int sum=total-target;
        if(sum<0 || sum%2==1)return 0;
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));

        return helper(n-1,sum/2,nums,dp);
        
    }
};
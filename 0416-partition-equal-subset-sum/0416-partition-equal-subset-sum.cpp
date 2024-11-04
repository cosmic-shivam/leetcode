class Solution {
public:
    bool helper(int n,vector<int>& nums,int target,vector<vector<int>>&dp)
    {
        if(target==0)return 1;

        if(n==0)return nums[0]==target;  //return true is target is equal to last element
        
        if(dp[n][target]!=-1)return dp[n][target];
        int take=0;
        if(target>=nums[n])
        {
            take=helper(n-1,nums,target-nums[n],dp);
        }
        int nottake=helper(n-1,nums,target,dp);
        return dp[n][target]=(take || nottake);
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;

        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
        }
        if(sum%2==1)return false;
        int target=sum/2;
        vector<vector<int>>dp(n,vector<int>(target+1,-1));

        return helper(n-1,nums,target,dp);
        
    }
};
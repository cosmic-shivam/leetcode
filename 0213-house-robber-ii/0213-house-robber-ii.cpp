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
        if (n == 1) return nums[0];
        vector<int>dp1(n-1,-1);
        vector<int>dp2(n-1,-1);

        vector<int>temp1,temp2;
        for(int i=0;i<n;i++)
        {
            if(i!=0)temp1.push_back(nums[i]);
        }
        for(int i=0;i<n;i++)
        {
            if(i!=n-1)temp2.push_back(nums[i]);
        }

        int count1=cal(n-2,temp1,dp1);
        int count2=cal(n-2,temp2,dp2);
        return max(count1,count2);
        
    }
};
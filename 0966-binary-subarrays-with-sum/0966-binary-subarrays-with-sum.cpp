class Solution {
public:
    int fun(vector<int>& nums, int goal) 
    {
        if(goal<0)return 0;
        int i=0,j=0,count=0;
        long long int sum=0;
        int n=nums.size();
        while(j<n)
        {
            sum+=nums[j];
            while(sum>goal)
            {
                sum=sum-nums[i];
                i++;
            }
            count+=j-i+1;
            j++;
        }
         return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {

        return fun(nums, goal)-fun(nums,goal-1);
        
    }
};
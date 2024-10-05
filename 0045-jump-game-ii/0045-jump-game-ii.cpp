class Solution {
public:
    int jump(vector<int>& nums) {
        int low=0;
        int high=0;
        int n=nums.size();
        int far=0;
        int jumps = 0;

        while(high<n-1)
        {
            far=0;
            for(int i=low;i<=high;i++)
            {
                far=max(far,nums[i]+i);
            }
            low=high+1;
            high=far;
            jumps+=1;
            
        }
        return jumps;
        
    }
};
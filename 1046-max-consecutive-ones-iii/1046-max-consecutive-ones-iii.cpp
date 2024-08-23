class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int count=0;
        int i=0,j=0;
        int store=0;
        int maxi=0;
        while(j<n)
        {
            if(nums[j]==0)
            {
                count++;
            }
            // while(count>k)
            // {
            //     if(nums[i]==0)
            //     {
            //         count--;
            //     }
            //     i++;
            // }
            if(count>k){
                if(nums[i]==0)count--;
                i++;
            }
            if(count<=k)
            {
                store=j-i+1;
                maxi=max(maxi,store);
            }
            j++;

        }
        return maxi;
        
    }
};
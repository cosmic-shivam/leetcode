class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        int sum=0;
        int x=0;
        map<int,int>mpp;
        for(int i=0;i<n;i++)
        {
            x=target-nums[i];
            if(mpp.find(x)!=mpp.end())
            {
                return {mpp[x],i};
            }
            mpp[nums[i]]=i;


        }

        

        return {};
        
    }
};
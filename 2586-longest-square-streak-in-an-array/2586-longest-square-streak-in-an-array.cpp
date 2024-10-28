class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mpp;
        int result=-1;

        sort(nums.begin(),nums.end());
        

        for(int i=0;i<n;i++)
        {
            int sqr=sqrt(nums[i]);
            if(sqr*sqr==nums[i] &&  mpp.find(sqr)!=mpp.end())
            {

                mpp[nums[i]]=mpp[sqrt(nums[i])]+1;
                result=max(mpp[nums[i]],result);

            }
            else{
                mpp[nums[i]]=1;
            }
        }
        return  result;
        
    }
};
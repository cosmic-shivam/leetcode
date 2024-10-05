class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int j=0;
        int maxind=0;

        for(int i=0;i<n;i++)
        {
            if(i>maxind)return false;
            if(maxind>=n-1)return true;

            j=i+nums[i];
            maxind=max(maxind,j);
        }
        
        return true;
        
    }
};
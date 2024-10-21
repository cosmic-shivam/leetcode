class Solution {
public:
    
    vector<vector<int>> sol(vector<int>& nums, int ind, vector<int>temp, vector<vector<int>>&ans)
    {
        ans.push_back(temp);

        for(int i=ind;i<nums.size();i++)
        {
            if(i!=ind && nums[i]==nums[i-1]) continue;
            temp.push_back(nums[i]);
            sol(nums,i+1,temp,ans);
            temp.pop_back();

        }
        return ans;
    }
   
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        vector<int > temp;

        ans= sol(nums, 0,temp,ans);
        return ans;
    }
};
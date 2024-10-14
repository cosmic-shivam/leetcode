class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int>ans;
        int n=nums.size();
        long long sol=0;
        double temp=0;

        for(int i=0;i<n;i++)
        {
            ans.push(nums[i]);
        }
        while(k>0)
        {
            sol+=ans.top();
            temp=ans.top();
            ans.pop();
            ans.push(ceil(temp/3));
            k--;
        }

        return sol;


        
    }
};
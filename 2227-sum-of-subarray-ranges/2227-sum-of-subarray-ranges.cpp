class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
         int n = nums.size();
    long long ans = 0;

    // Calculate the sum of all maximums
    for (int i = 0; i < n; i++) {
        int maxEle = nums[i], minEle = nums[i];
        for (int j = i; j < n; j++) {
            maxEle = max(maxEle, nums[j]);
            minEle = min(minEle, nums[j]);
            ans += (maxEle - minEle);
        }
    }
    
    return ans;
        
    }
};
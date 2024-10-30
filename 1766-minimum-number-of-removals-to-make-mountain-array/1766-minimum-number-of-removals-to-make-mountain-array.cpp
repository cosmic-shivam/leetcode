class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {

         int n = nums.size();
    
    // Step 1: Find LIS from the left
    vector<int> lis(n, 1);
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[i] > nums[j]) {
                lis[i] = max(lis[i], lis[j] + 1);
            }
        }
    }
    
    // Step 2: Find LDS from the right
    vector<int> lds(n, 1);
    for (int i = n - 2; i >= 0; --i) {
        for (int j = n - 1; j > i; --j) {
            if (nums[i] > nums[j]) {
                lds[i] = max(lds[i], lds[j] + 1);
            }
        }
    }
    
    // Step 3: Calculate the maximum length of the mountain
    int maxMountainLength = 0;
    for (int i = 1; i < n - 1; ++i) { // i should be between 1 and n-2
        if (lis[i] > 1 && lds[i] > 1) {
            maxMountainLength = max(maxMountainLength, lis[i] + lds[i] - 1);
        }
    }
    
    // Step 4: Calculate minimum removals
    return n - maxMountainLength;
        
    }
};
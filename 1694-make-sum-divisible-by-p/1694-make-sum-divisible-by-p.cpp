class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
    
    // Calculate the total sum of the array modulo p
    int totalSum = accumulate(nums.begin(), nums.end(), 0LL) % p;
    
    // If the total sum is already divisible by p, return 0 (no need to remove any subarray)
    if (totalSum == 0) return 0;
    
    // HashMap to store the latest index of each prefix sum modulo p
    unordered_map<int, int> prefixModMap;
    prefixModMap[0] = -1; // Handle the case where subarray starts from index 0
    
    int prefixSum = 0;
    int minLength = n;  // Initialize the minimum length to n (max possible length)
    
    for (int i = 0; i < n; ++i) {
        // Update the prefix sum and take its modulo with p
        prefixSum = (prefixSum + nums[i]) % p;
        
        // We need to find if we have seen (prefixSum - totalSum + p) % p before
        int targetMod = (prefixSum - totalSum + p) % p;
        
        // Check if the targetMod exists in the map
        if (prefixModMap.find(targetMod) != prefixModMap.end()) {
            // Update the minimum length
            minLength = min(minLength, i - prefixModMap[targetMod]);
        }
        
        // Store the current prefix sum mod p in the map
        prefixModMap[prefixSum] = i;
    }
    
    // If we found a valid subarray length, return it; otherwise, return -1
    return minLength == n ? -1 : minLength;
        
    }
};
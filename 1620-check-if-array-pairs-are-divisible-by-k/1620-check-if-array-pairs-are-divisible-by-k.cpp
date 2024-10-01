class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> remainderCount(k, 0);
        
        // Count remainders
        for (int num : arr) {
            int remainder = ((num % k) + k) % k; // Handle negative numbers
            remainderCount[remainder]++;
        }
        
        // Check pairing
        for (int i = 1; i < k; ++i) {
            if (remainderCount[i] != remainderCount[k - i]) {
                return false;
            }
        }
        
        // Special case for remainder 0
        if (remainderCount[0] % 2 != 0) {
            return false;
        }
        
        return true;
    }
};
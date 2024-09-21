class Solution {
public:
    vector<int> lexicalOrder(int n) {
    vector<int> result;
    int curr = 1;
    
    // Generate numbers in lexicographical order
    for (int i = 0; i < n; ++i) {
        result.push_back(curr);
        
        // Try to go deeper by multiplying by 10
        if (curr * 10 <= n) {
            curr *= 10;
        } 
        // If we cannot go deeper, we increment the current number
        else {
            if (curr >= n) curr /= 10; // Go up if needed
            ++curr; 
            // If the last digit becomes 10, we need to trim the last 0s
            while (curr % 10 == 0) curr /= 10;
        }
    }
    
    return result;
    }
};
class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
             priority_queue<pair<int, char>> pq;
        
        if (a > 0) pq.push({a, 'a'});
        if (b > 0) pq.push({b, 'b'});
        if (c > 0) pq.push({c, 'c'});
        
        string result = "";
        
        while (!pq.empty()) {
            // Take the most frequent character
            auto [count1, char1] = pq.top();
            pq.pop();
            
            // Check if we can add this character
            int n = result.size();
            if (n >= 2 && result[n-1] == char1 && result[n-2] == char1) {
                // If adding this character would violate the rule, try the next most frequent
                if (pq.empty()) break; // No more characters to add
                
                auto [count2, char2] = pq.top();
                pq.pop();
                
                // Add the second most frequent character instead
                result += char2;
                count2--;
                
                // Push it back if there's any remaining of char2
                if (count2 > 0) pq.push({count2, char2});
                
                // Push the first character back as well
                pq.push({count1, char1});
                
            } else {
                // Safe to add the most frequent character
                result += char1;
                count1--;
                
                // Push it back if there's any remaining of char1
                if (count1 > 0) pq.push({count1, char1});
            }
        }
        
        return result;
    } 
    
};
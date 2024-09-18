class Solution {
public:
    static bool compare(string &a, string &b) {
        return a + b > b + a;
    }
    
    string largestNumber(vector<int>& nums) {
        // Convert all integers to strings
        vector<string> numStrings;
        for (int num : nums) {
            numStrings.push_back(to_string(num));
        }
        
        // Sort strings based on custom comparator
        sort(numStrings.begin(), numStrings.end(), compare);
        
        // If the largest number is "0", return "0"
        if (numStrings[0] == "0") return "0";
        
        // Build the largest number string
        string result;
        for (string &s : numStrings) {
            result += s;
        }
        
        return result;
    }
};
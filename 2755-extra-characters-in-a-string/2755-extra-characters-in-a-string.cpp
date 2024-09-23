class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.size();
    unordered_set<string> dict(dictionary.begin(), dictionary.end());
    vector<int> dp(n + 1, INT_MAX);  // dp[i] will store the minimum extra characters for the prefix of length i
    dp[0] = 0;  // No extra characters for an empty prefix

    // Iterate over all prefixes of the string
    for (int i = 1; i <= n; ++i) {
        // Assume the entire substring s[0:i-1] is extra
        dp[i] = dp[i - 1] + 1;  // Extra character added

        // Check all possible substrings ending at i-1 and starting at j
        for (int j = 0; j < i; ++j) {
            string substring = s.substr(j, i - j);
            if (dict.count(substring)) {
                dp[i] = min(dp[i], dp[j]);  // If substring is found in the dictionary, no extra chars added
            }
        }
    }

    return dp[n];
        
        
    }
};
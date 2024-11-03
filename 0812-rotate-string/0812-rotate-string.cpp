class Solution {
public:
    bool rotateString(string s, string goal) {
    if (s.length() != goal.length()) return false;

    int n = s.length();
    for (int i = 0; i < n; ++i) {
        // Check if rotating s by i positions matches goal
        if (s.substr(i) + s.substr(0, i) == goal) {
            return true;
        }
    }
    return false;
    }
};
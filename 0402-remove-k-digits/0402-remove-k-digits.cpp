class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        int n = num.size();

        // Traverse through the digits of the number
        for (int i = 0; i < n; i++) {
            // Pop from the stack if the current digit is smaller than the top of the stack
            // and we still need to remove more digits (k > 0)
            while (!st.empty() && k > 0 && st.top() > num[i]) {
                st.pop();
                k--;
            }
            // Avoid pushing leading zeroes unless the stack is empty
            if (!st.empty() || num[i] != '0') {
                st.push(num[i]);
            }
        }

        // If k is still greater than 0, remove the remaining top elements
        while (k > 0 && !st.empty()) {
            st.pop();
            k--;
        }

        // Build the resulting string from the stack
        string res;
        while (!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }

        // The digits are in reverse order, so reverse the result
        reverse(res.begin(), res.end());

        // If the result is empty, return "0"
        return res.empty() ? "0" : res;
    }
};
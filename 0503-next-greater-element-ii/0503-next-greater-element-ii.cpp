class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
    vector<int> ans(n, -1); // Initialize ans with -1
    stack<int> st; // This stack holds indices, not values

    // Iterate through the array twice to handle the circular condition
    for (int i = 0; i < 2 * n; ++i) {
        int num = nums[i % n]; // Circular access to the array
        // While the stack is not empty and the current element is greater than
        // the element represented by the index on the top of the stack
        while (!st.empty() && nums[st.top()] < num) {
            ans[st.top()] = num;
            st.pop();
        }
        if (i < n) {
            // Push the index of the current element onto the stack
            st.push(i);
        }
    }
    return ans;
    }
};
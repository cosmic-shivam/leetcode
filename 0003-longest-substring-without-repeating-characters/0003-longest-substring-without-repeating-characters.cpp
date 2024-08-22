class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        vector<int> hash(256, -1);  // Initialize hash array with -1
    int l = 0, r = 0;           // Left and right pointers for the sliding window
    int n = s.size();           // Length of the input string
    int maxi = 0;               // Maximum length of substring without repeating characters

    while (r < n) {
        // If the character at position r has been seen before and is within the current window
        if (hash[s[r]] != -1) {
            // Move the left pointer to the right of the previous occurrence of s[r]
            l = max(hash[s[r]] + 1, l);
        }

        // Calculate the current window size and update the maximum size found
        maxi = max(r - l + 1, maxi);

        // Update the last index of the current character
        hash[s[r]] = r;

        // Move the right pointer to expand the window
        r++;
    }

    return maxi;  // Return the maximum length of substring without repeating characters
}


















    
    // Brute force Approach:

    // int arr[256] = {0}; // Array to store the count of each character
    // int n = s.size();
    // int maxi = 0; // To store the maximum length found
    // int i = 0, j = 0; // Two pointers to define the current window

    // while (j < n) {
    //     if (arr[s[j]] == 0) { // If character is not in the current substring
    //         arr[s[j]] = 1; // Mark the character as seen
    //         j++; // Expand the window
    //         maxi = std::max(maxi, j - i); // Update the maximum length
    //     } else { // If character is already in the substring
    //         arr[s[i]] = 0; // Remove the character at the start of the window
    //         i++; // Shrink the window
    //     }
    // }

    // return maxi;
    
};
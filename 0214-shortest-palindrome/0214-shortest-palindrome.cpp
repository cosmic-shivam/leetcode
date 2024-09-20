class Solution {
public:
    string shortestPalindrome(string s) {
     string rev = s; 
    reverse(rev.begin(), rev.end());
    
    string combined = s + "#" + rev;  // Combine the original and reversed string with a separator
    
    vector<int> lps(combined.size(), 0);  // Longest Prefix Suffix (LPS) array for KMP algorithm
    
    // Compute the LPS array (KMP preprocessing)
    for (int i = 1; i < combined.size(); i++) {
        int j = lps[i - 1];
        while (j > 0 && combined[i] != combined[j]) {
            j = lps[j - 1];
        }
        if (combined[i] == combined[j]) {
            j++;
        }
        lps[i] = j;
    }
    
    // The LPS value for the combined string tells us the length of the longest palindrome starting at index 0.
    int palindromeLength = lps.back();
    
    // Append the non-palindromic suffix of the reversed string to the front of the original string
    string toAdd = rev.substr(0, s.size() - palindromeLength);
    return toAdd + s;   
    }
};
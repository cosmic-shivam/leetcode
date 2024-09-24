class Solution {
public:
    // Helper function to find the length of the common prefix between two strings
int findCommonPrefixLength(const string& a, const string& b) {
    int i = 0;
    while (i < a.size() && i < b.size() && a[i] == b[i]) {
        i++;
    }
    return i;  // Return the length of the common prefix
}

int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
    int maxPrefixLength = 0;  // Track the longest common prefix length

    // Convert integers to strings for comparison
    vector<string> strArr1, strArr2;
    for (int num1 : arr1) strArr1.push_back(to_string(num1));
    for (int num2 : arr2) strArr2.push_back(to_string(num2));
    
    // Sort both arrays based on string representation
    sort(strArr1.begin(), strArr1.end());
    sort(strArr2.begin(), strArr2.end());

    // Two-pointer technique to compare possible pairs with the longest common prefix
    int i = 0, j = 0;
    while (i < strArr1.size() && j < strArr2.size()) {
        // Compare the current pair
        int commonPrefixLength = findCommonPrefixLength(strArr1[i], strArr2[j]);
        maxPrefixLength = max(maxPrefixLength, commonPrefixLength);

        // Move the pointer for the lexicographically smaller string
        if (strArr1[i] < strArr2[j]) {
            i++;
        } else {
            j++;
        }
    }

    return maxPrefixLength;
}
};
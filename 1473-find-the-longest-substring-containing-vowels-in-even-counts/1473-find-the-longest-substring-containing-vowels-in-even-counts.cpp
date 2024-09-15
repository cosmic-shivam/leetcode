class Solution {
public:
    int findTheLongestSubstring(string s) {
        // Vowel mask bit representation: a = 1, e = 2, i = 4, o = 8, u = 16
    unordered_map<int, int> maskIndex;  // Store first occurrence of each mask
    maskIndex[0] = -1;  // Initial state, no vowels, corresponds to mask 0

    int mask = 0;  // Current bitmask (5 bits for vowels)
    int maxLength = 0;

    for (int i = 0; i < s.size(); i++) {
        // Update the bitmask based on the current character
        if (s[i] == 'a') mask ^= (1 << 0);
        else if (s[i] == 'e') mask ^= (1 << 1);
        else if (s[i] == 'i') mask ^= (1 << 2);
        else if (s[i] == 'o') mask ^= (1 << 3);
        else if (s[i] == 'u') mask ^= (1 << 4);

        // If this mask has been seen before, calculate the length of the substring
        if (maskIndex.find(mask) != maskIndex.end()) {
            maxLength = max(maxLength, i - maskIndex[mask]);
        } else {
            maskIndex[mask] = i;  // Store the first occurrence of this mask
        }
    }

    return maxLength;
    }
};
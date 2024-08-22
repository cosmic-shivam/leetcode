class Solution {
public:
    int findComplement(int num) {
    if (num == 0) return 1;  // Special case for 0
    
    // Handle INT_MIN case explicitly if needed
    if (num == INT_MIN) {
        // Specific logic for INT_MIN if applicable
    }

    // Calculate the number of bits in num
    int bitLength = log2(num) + 1;

    // Create a bitmask with all bits set to 1 for the bitLength
    unsigned int bitmask = (1U << bitLength) - 1;

    // XOR num with bitmask to get the complement
    return num ^ bitmask;
        
    }
};
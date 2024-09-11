class Solution {
public:
    int minBitFlips(int start, int goal) {
    int xorResult = start ^ goal;  // XOR to find differing bits
    int flips = 0;

    // Count the number of set bits in xorResult
    while (xorResult > 0) {
        flips += xorResult % 2;    // Add 1 if the last bit is set
        xorResult /= 2;            // Shift right to process the next bit
    }

    return flips;
        
    }
};
class Solution {
public:
    int minSteps(int n) {
         int count = 0;
    int factor = 2;

    while (n > 1) {
        while (n % factor == 0) {
            count += factor;
            n /= factor;
        }
        factor++;
    }

    return count;    
    }
};
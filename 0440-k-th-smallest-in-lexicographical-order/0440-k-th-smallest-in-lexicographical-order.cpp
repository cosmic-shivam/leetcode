class Solution {
public:
    int countSteps(long long curr, long long n) {
    long long steps = 0;
    long long first = curr;
    long long last = curr;
    
    // We are calculating how many numbers are between 'first' and 'last' in the lexicographical order.
    while (first <= n) {
        steps += min(n + 1, last + 1) - first;
        first *= 10;
        last = last * 10 + 9;
    }
    
    return steps;
}

    int findKthNumber(int n, int k) {
        long long curr = 1; // Start from the smallest number in lexicographical order
    k--; // Decrement k because we're counting from 0 now (curr is the first number)
    
    while (k > 0) {
        int steps = countSteps(curr, n);
        
        // If the kth number is in the current subtree, explore that subtree.
        if (steps <= k) {
            k -= steps;  // We skip the entire subtree rooted at 'curr'
            curr++;      // Move to the next sibling node
        } else {
            curr *= 10;  // Explore the subtree rooted at 'curr'
            k--;         // Move to the next level, decreasing k
        }
    }
    
    return curr;
        
    }
};
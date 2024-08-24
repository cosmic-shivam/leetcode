class Solution {
public:
    string nearestPalindromic(string n) {
    int len = n.size();
    vector<long> candidates;

    // Edge case for "1000...0001"
    candidates.push_back((long)pow(10, len) + 1);
    // Edge case for "999...999"
    candidates.push_back((long)pow(10, len - 1) - 1);

    // Create the prefix and mirror it
    long prefix = stol(n.substr(0, (len + 1) / 2));
    
    // Generate palindromes by mirroring the prefix
    for (int i = -1; i <= 1; i++) {
        string p = to_string(prefix + i);
        string palin = p + string(p.rbegin() + (len % 2), p.rend());
        candidates.push_back(stol(palin));
    }

    // Remove the original number itself from the list of candidates
    long num = stol(n);
    long closest = -1;
    for (long cand : candidates) {
        if (cand != num) {
            if (closest == -1 ||
                abs(cand - num) < abs(closest - num) ||
                (abs(cand - num) == abs(closest - num) && cand < closest)) {
                closest = cand;
            }
        }
    }
    return to_string(closest);
}
};
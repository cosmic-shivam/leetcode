class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {

        unordered_map<char,int>mpp;
        int o=order.size();

        for(int i=0;i<o;i++)
        {
            mpp[order[i]]=i;
        }

        for(int i=0;i<words.size()-1;i++)
        {
            string word1 = words[i];
            string word2 = words[i + 1];

              int minLength = min(word1.size(), word2.size());
              bool foundDifference = false;

              for (int j = 0; j < minLength; j++) {
              if (mpp[word1[j]] < mpp[word2[j]]) {
                foundDifference = true;
                break;
            } else if (mpp[word1[j]] > mpp[word2[j]]) {
                return false; // Not sorted
            }
        }

        // If no difference found and word1 is longer than word2, they are not sorted
        if (!foundDifference && word1.size() > word2.size()) {
            return false;
        }
    }
    return true;
        
    }
};
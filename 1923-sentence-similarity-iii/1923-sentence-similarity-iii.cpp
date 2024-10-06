class Solution {
public:
    vector<string> splitSentence(string sentence) {
    vector<string> words;
    stringstream ss(sentence);
    string word;
    while (ss >> word) {
        words.push_back(word);
    }
    return words;
}

bool areSentencesSimilar(string sentence1, string sentence2) {
    // Split both sentences into words
    vector<string> words1 = splitSentence(sentence1);
    vector<string> words2 = splitSentence(sentence2);
    
    // Ensure words1 is the shorter one
    if (words1.size() > words2.size()) {
        swap(words1, words2);
    }
    
    int n1 = words1.size();
    int n2 = words2.size();
    
    // Compare common prefix
    int i = 0;
    while (i < n1 && words1[i] == words2[i]) {
        i++;
    }
    
    // Compare common suffix
    int j = 0;
    while (j < n1 && words1[n1 - 1 - j] == words2[n2 - 1 - j]) {
        j++;
    }
    
    // If all words from the shorter sentence are matched in prefix and suffix, return true
    return i + j >= n1;
}
};
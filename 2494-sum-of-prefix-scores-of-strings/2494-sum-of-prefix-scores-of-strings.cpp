class Solution {
public:
    class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    int count; // Number of words that have this prefix

    TrieNode() {
        count = 0;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    // Insert word into the Trie and update the prefix counts
    void insert(const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            if (node->children.find(c) == node->children.end()) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
            node->count++; // Increment the count for this prefix
        }
    }

    // Get the sum of prefix scores for a given word
    int getPrefixScore(const string& word) {
        TrieNode* node = root;
        int score = 0;
        for (char c : word) {
            node = node->children[c];
            score += node->count; // Add the count of words with this prefix
        }
        return score;
    }
};

vector<int> sumPrefixScores(vector<string>& words) {
    Trie trie;

    // Step 1: Insert all words into the Trie
    for (const string& word : words) {
        trie.insert(word);
    }

    // Step 2: Calculate the sum of prefix scores for each word
    vector<int> result;
    for (const string& word : words) {
        result.push_back(trie.getPrefixScore(word));
    }

    return result;
}
};
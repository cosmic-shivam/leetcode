class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string>ans;
        string temp="";
        int n=s1.size();
        unordered_map<string,int>mpp;
        for(int i=0;i<=n;i++)
        {
            if (i == s1.size() || s1[i] == ' ') {  // End of word
                if (!temp.empty()) {
                    mpp[temp]++;
                    temp = "";
                }
            } else {
                temp += s1[i];
        }
        }
        int m=s2.size();
        for(int i=0;i<=m;i++)
        {
           if (i == s2.size() || s2[i] == ' ') {  // End of word
                if (!temp.empty()) {
                    mpp[temp]++;
                    temp = "";
                }
            } else {
                temp += s2[i];
            }
        }
        for(auto ss:mpp)
        {
            if(ss.second==1)ans.push_back(ss.first);
        }
        return ans;


        
    }
};
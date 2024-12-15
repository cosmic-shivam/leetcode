class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mpp;
        vector<vector<string>>ans;
        for(auto s:strs)
        {
            string ss=s;
            sort(s.begin(),s.end());
            mpp[s].push_back(ss);
        }
        for(auto mp:mpp)
        {
            ans.push_back(mp.second);
        }
        return ans;

        
    }
};
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        map<char,int>mpp1;
        map<char,int>mpp2;
        int n=s1.size();
        int m=s2.size();

        for(int i=0;i<n;i++)
        {
            mpp1[s1[i]-'a']++;
            mpp2[s2[i]-'a']++;
        }
        if(mpp1==mpp2)return true;

        for(int i=n;i<=m;i++)
        {
            mpp2[s2[i]-'a']++;
            mpp2[s2[i-n]-'a']--;
             if (mpp2[s2[i - n] - 'a'] == 0) {
            mpp2.erase(s2[i - n] - 'a');
        }


            if(mpp1==mpp2)return true;
        }
        return false;
        
    }
};
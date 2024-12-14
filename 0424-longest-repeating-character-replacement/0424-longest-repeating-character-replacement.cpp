class Solution {
public:
    int characterReplacement(string s, int k) {
        int hash[26]={0};
        int maxfrq=0;
        int left=0;
        int n=s.size();
        int maxwin=0;

        for(int j=0;j<n;j++)
        {
            hash[s[j]-'A']++;
            maxfrq=max(maxfrq,hash[s[j]-'A']);

            int windowlen=j-left+1;

            if(windowlen-maxfrq>k)
            {
                hash[s[left]-'A']--;
                left++;
            }

            windowlen=j-left+1;

            maxwin=max(maxwin,windowlen);

        }
        return maxwin;


        
    }
};
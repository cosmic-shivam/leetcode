class Solution {
public:
    int characterReplacement(string s, int k) {
        int hash[26]={0};
        int n=s.size();
        int i=0,j=0;
        int maxlen=0;
        int maxf=0;
        int count=0;
        while(j<n)
        {
            hash[s[j]-'A']++;
            maxf=max(maxf,hash[s[j]-'A']);

            while((j-i+1)-maxf>k)
            {
                hash[s[i]-'A']--;
                maxf=0;
                for(int i=0;i<25;i++){
                    maxf=max(maxf,hash[i]);
                }
                i++;
            }
            if((j-i+1)-maxf<=k)
            {
                maxlen=max(maxlen,j-i+1);
                j++;
            }
            


        }
        return maxlen;
        
    }
};
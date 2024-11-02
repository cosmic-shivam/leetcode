class Solution {
public:
    bool isCircularSentence(string s) {
        char first;
        char last;
        int n=s.size();
        first=s[0];
        for(int i=0;i<n;i++)
        {
            if(s[i]==' ')
            {
                last=s[i-1];
                if(i+1<=n-1)
                {
                    if(last!=s[i+1])return false;
                }
            }
            else{
                last=s[i];
            }
        }
        if(first!=last)return false;

        return true;
        
    }
};
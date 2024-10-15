class Solution {
public:
    long long minimumSteps(string s) {
        int n=s.size();
        int i=0,j=0;
        long long ans=0;
        while(j<n)
        {
            if(s[j]=='0')
            {
                ans+=j-i;
                i++;
            }
            j++;

        }
        return ans;
        
    }
};
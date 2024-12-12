class Solution {
public:
    bool isPalindrome(string s) {
        string ans;
        int n=s.size();
        for(char ch:s)
        {
            char st=tolower(ch);
            if((int(st)>=97 && int(st)<=122)||(int(st)>=48 && int(st)<=57))
            {
                ans+=st;
            }
        }
        int m=ans.size();
        int i=0;
        int j=m-1;
        while(i<j)
        {
            if(ans[i]==ans[j])
            {
                i++;
                j--;
            }
            else{
                return false;
            }
        }
        return true;
        
    }
};
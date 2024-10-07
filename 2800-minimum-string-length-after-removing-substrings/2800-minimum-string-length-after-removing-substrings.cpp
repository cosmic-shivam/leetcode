class Solution {
public:
    int minLength(string s) {
        int n=s.size();
        stack<char>st;
        // int count=n;

        for(int i=0;i<n;i++)
        {
        if(!st.empty() && s[i]=='B' && st.top()=='A')
        {
            st.pop();
        }
        else if ( !st.empty() && s[i]=='D'&& st.top()=='C')
        {
            st.pop();
        }
        else{
            st.push(s[i]);
        }


        }
        return st.size();

        
    }
};
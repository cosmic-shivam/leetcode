class Solution {
public:
    string clearDigits(string s) {
        stack<char>st;
        int n=s.size();
        string ans="";
        for(char ch : s)
        {
            if(isdigit(ch)){
                if(!st.empty())
                {
                    st.pop();
                }

            }
            else{
                st.push(ch);
            }
        }
        while(!st.empty())
        {
            char temp=st.top();
            ans=temp+ans;
            st.pop();

        }
        return ans;
        
    }
};
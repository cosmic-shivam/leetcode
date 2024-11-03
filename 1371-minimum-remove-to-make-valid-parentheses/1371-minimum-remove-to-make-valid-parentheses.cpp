class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n=s.size();
        int check=0;
        string ans="";
        for(int i=0;i<n;i++)
        {
            if(s[i]=='('){
                check++;
                ans.push_back(s[i]);
            }
            else if (s[i] == ')') {
                if (check > 0) {
                check--; 
                ans.push_back(s[i]);
            }
        } else {
            
            ans.push_back(s[i]);
        }
        }
        string result; 
        result.reserve(ans.size());


            for(int i=ans.size()-1;i>=0;i--)
            {
                if(check>0 && ans[i]=='(')
                {
                    check--;
                    continue;
                }

                 result.push_back(ans[i]);



            }
            reverse(result.begin(), result.end());
    
            return result;

        }
        

        
    
};
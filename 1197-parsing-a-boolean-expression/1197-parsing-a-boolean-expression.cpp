class Solution {
public:
    char evaluate(vector<char>&v,char op)
    {
        if(op=='&')
        {
            if(finder(v,'f')){
                return 'f';
            }
            else
            {
              return 't';
            }  
        }
        else if(op=='|')
        {
            if(finder(v,'t'))
            {
                return 't';
            }
            else
            {
                return 'f';
            }
        }
        else if(op=='!')
        {
            return (v[0]=='t')?'f':'t';
        }
        return 'm';
    }
    bool finder(vector<char>&v,char val)
    {
        for(char ch:v)
        {
            if(ch==val)return true;

        }
        return false;
    }

    bool parseBoolExpr(string exp) {
        stack<char>st;
        int n=exp.size();
        int i=0;
        for(int i=0;i<n;++i)
        {
            if(exp[i]=='t' ||exp[i]=='f'|| exp[i]=='&' || exp[i]=='|' || exp[i]=='!' || exp[i]=='(')
            {
                st.push(exp[i]);
            }
            else if(exp[i]==')')
            {
                vector<char>v;
                while(st.top()!='(')
                {
                    char ch=st.top();
                    st.pop();
                    if(ch=='f' ||ch=='t')
                    {
                        v.push_back(ch);
                    }
                }
                st.pop();  //  '(' pop
                char op=st.top();
                st.pop();
                char ans=evaluate(v,op);
                st.push(ans);
            }
        }  
        return (st.top()=='t')?true:false;    
        
    }
};
class Solution {
public:


    void backtrack(string s , int n, int index , set<string>&st,int & count)
    {
        if(n==index)
        {
            count=max(count,(int)st.size());
            return;
        }

        for(int i=index;i<n;i++ )
        {
            string sub=s.substr(index,i-index+1);
            if(st.find(sub) == st.end())
            {
                st.insert(sub);
                backtrack(s,n,i+1,st,count);
                st.erase(sub);
            }
        }
    }
    int maxUniqueSplit(string s) {
        int n=s.size();
        set<string>st;
        int count=0;
        backtrack(s,n,0,st,count);
        return count;
        
        
    }
};
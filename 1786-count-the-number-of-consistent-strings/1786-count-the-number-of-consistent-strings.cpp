class Solution {
public:

    int check(map<char,int>mpp,string st)
    {
        int n=st.size();
        for(int i=0;i<n;i++)
        {
            if(mpp.find(st[i])!=mpp.end())continue;
            else return 0;
        }
        return 1;


    }
    int countConsistentStrings(string allowed, vector<string>& words) {

        map<char,int>mpp;
        int n=allowed.size();
        int m=words.size();
        int sum=0;
        for(int i=0;i<n;i++)
        {
            mpp[allowed[i]]=1;
        }

        for(int i=0;i<m;i++)
        {
            sum+=check(mpp,words[i]);
            

        }
        return sum;
        
    }
};
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        int count=0;
        string str;
        int min=INT_MAX;
        for(int i=0;i<n;i++)
        {
            int len=strs[i].size();
            if(len<min)
            {
                min=len;
                str=strs[i];
            }
        }
        for(int i=0;i<min;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(strs[j][i]!=str[i])return (count==0)?"":str.substr(0,count);
            }
            count++;
        }
        return (count==0)?"":str.substr(0,count);
        
    }
};
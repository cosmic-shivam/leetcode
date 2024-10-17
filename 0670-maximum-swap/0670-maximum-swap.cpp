class Solution {
public:
//Take array and store the index of maximum element of right hand side
    int maximumSwap(int num) {
        string s=to_string(num);
        int n=s.size();

        vector<int>ans(n,-1);
        ans[n-1]=n-1 ;

        for(int i=n-2;i>=0;i--)
        {
            if(s[i]-'0'>s[ans[i+1]]-'0')
            {
                ans[i]=i;
            }
            else{
                ans[i]=ans[i+1];
            }
        }
        for(int i=0;i<n;i++)
        {
            if(s[i]<s[ans[i]]){
                swap(s[i],s[ans[i]]);
                break;
            }
        }

        return stoi(s);
        
    }
};
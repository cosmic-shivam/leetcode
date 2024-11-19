class Solution {
public:
int helper(string &s1,string &s2,int n,int m,vector<vector<int>>&dp)
    {
        if(n<0 || m<0)return 0;
        if(dp[n][m]!=-1)return dp[n][m];

        int take=0;
        int nottake=0;
        if(s1[n]==s2[m])
        {
            take=1+helper(s1,s2,n-1,m-1,dp);
        }
        else{
            nottake=max((helper(s1,s2,n-1,m,dp)),(helper(s1,s2,n,m-1,dp)));
        }
        return dp[n][m]=max(take,nottake);
        


    }
    int minDistance(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));

        int lcs= helper(s1,s2,n-1,m-1,dp);
        
        return n+m-2*lcs;
        
    }
};
class Solution {
public:

    // int helper(string &text1,int n,string &text2,int m,vector<vector<int>>&dp)
    // {
    //     if(n<0 || m<0)return 0;

    //     if(dp[n][m]!=-1)return dp[n][m];

    //     if(text1[n]==text2[m])return dp[n][m]=1+helper(text1,n-1,text2,m-1,dp);

    //     return max(helper(text1,n-1,text2,m,dp),helper(text1,n,text2,m-1,dp));

    // }
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();

        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        // return helper(text1,n-1,text2,m-1,dp);

        for(int i=0;i<=n;i++)
        {
            dp[i][0]=0;
        }
        for(int j=0;j<=m;j++)
        {
            dp[0][j]=0;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(text1[i-1]==text2[j-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][m];

        
    }
};
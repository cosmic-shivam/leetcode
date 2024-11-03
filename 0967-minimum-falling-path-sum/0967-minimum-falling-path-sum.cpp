class Solution {
public:

    // int helper(int n,int m,vector<vector<int>>& matrix,vector<vector<int>>& dp,int i,int j)
    // {
    //     if(j<0 || j>=m)return 1e9;
    //     if(i==0)return matrix[0][j];

    //     if(dp[i][j]!=-1)return dp[i][j];

    //     int s=matrix[i][j]+helper(n,m,matrix,dp,i-1,j);
    //     int ld=matrix[i][j]+helper(n,m,matrix,dp,i-1,j-1);
    //     int rd=matrix[i][j]+helper(n,m,matrix,dp,i-1,j+1);

    //     return dp[i][j]=min(s,min(ld,rd));
    // }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();

        vector<vector<int>>dp(n,vector<int>(m,0));
        // int minPathSum = 1e9;
        // for(int i=0;i<n;i++)
        // {
        //     minPathSum=min( minPathSum ,helper(n,m,matrix,dp,n-1,i));

        // }
        // return minPathSum;
        for(int i=0;i<m;i++)
        {
            dp[0][i]=matrix[0][i]; //base case
        }

        for(int i=1;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int s=matrix[i][j]+dp[i-1][j];
                int ld=1e9;
                int rd=1e9;
                if(j>0) ld=matrix[i][j]+dp[i-1][j-1];

                if(j<m-1) rd=matrix[i][j]+dp[i-1][j+1];

                dp[i][j]=min({s,ld,rd});
            }
        }

        int mini=dp[n-1][0];
        for(int i=1;i<m;i++)
        {
            mini=min(mini,dp[n-1][i]);

        }
        return mini;



        
        
    }
};
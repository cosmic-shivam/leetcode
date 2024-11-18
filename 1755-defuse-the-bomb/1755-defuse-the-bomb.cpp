class Solution {
public:

    
    vector<int> decrypt(vector<int>& code, int k) {
        int n=code.size();
        vector<int>ans(n,0);
        if(k==0)return ans;
        int i=-1,j=-1;
        
        if(k>0)
        {
            i=1;
            j=k;

        }
        else{
            i=n-abs(k);
            j=n-1;
        }
        int totalsum=0;

        for(int k=i;k<=j;k++)
        {
            totalsum+=code[k];
        }
        for(int k=0;k<n;k++)
        {
            ans[k]=totalsum;

            totalsum-=code[i%n];
            i++;
            totalsum+=code[(j+1)%n];
            j++;
        }
        return ans;
        
        
        
    }
};
class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int>left(n);
        vector<int>right(n);
        left[0]=height[0];
        right[n-1]=height[n-1];
        int sum=0;
        int mini=INT_MAX;
        for(int i=1;i<n;i++)
        {
            left[i]=max(left[i-1],height[i]);
        }
        for(int j=n-2;j>=0;j--)
        {
            right[j]=max(right[j+1],height[j]);
        }

        for(int i=0;i<n;i++)
        {
            mini=min(left[i],right[i]);
            sum+=mini-height[i];
            
        }
        return sum;
        
    }
};
class Solution {
public:
int fun(vector<int>& nums, int k)
{
        if( k<0) return 0;
        int i=0,j=0,count=0;
        int sum=0;
        int n=nums.size();
        // int prefix_even=0;

        while(j<n)
        {
            sum+=nums[j]%2;

            while(sum>k)
            {
                sum-=nums[i]%2;
                i++;
            }
            count+=j-i+1;
            j++;

        }
        return count;
}
    int numberOfSubarrays(vector<int>& nums, int k) {
        
        return fun(nums,k)-fun(nums,k-1);
        
    }
};
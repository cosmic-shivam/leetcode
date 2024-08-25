class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int i=0,j=0,count=0;
        int checker=0;
        int n=nums.size();
        int prefix_even=0;

        while(j<n)
        {
            if(nums[j]%2==1)
            {
                checker++;
                prefix_even = 0;

            }
            while(checker==k)
            {
                // count++;
                if(nums[i] % 2==1){
                    checker--;
                }
                i++;
                prefix_even++;
            }
            count+=prefix_even;
            j++;


        }
        return count;
        
    }
};
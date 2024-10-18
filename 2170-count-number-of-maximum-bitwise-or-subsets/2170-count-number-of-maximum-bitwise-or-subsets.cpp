class Solution {
public:

    int recu(int target , vector<int>& nums, int index , int curor  )
    {
        if(index==nums.size())
        {
        
                return (curor==target)?1:0;
            
            
        }

        //pick

        int pick=recu(target,nums, index+1, curor | nums[index]);

        //notpick
        int notpick=recu(target,nums,index+1,curor);

        return pick+notpick;




    }
    int countMaxOrSubsets(vector<int>& nums) {
        int n=nums.size();
        int target=0;
        for(int i=0;i<n;i++)
        {
            target |=nums[i];
        }

        return recu(target , nums , 0, 0 );
    
        
    }
};
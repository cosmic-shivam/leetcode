class Solution {
public:

    void combi(int index,int target ,vector<int> &candidates ,int n, vector<int>&sol , vector<vector<int>>&finalsol )
    {

        //base condition
        if(index==n)
        {
            if(target==0)
            {
                finalsol.push_back(sol);
            }
            return;
        
        }

        if(candidates[index]<=target)  //pick condition
        {
            sol.push_back(candidates[index]);
            
        
        combi(index,target-candidates[index],candidates,n,sol,finalsol);  

        sol.pop_back(); // this line is means that you are coming back by try all posiible recursion by index 0 now we have to remove element of sol vector;
        }
        combi(index+1,target,candidates,n,sol,finalsol);  //not pick

    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n=candidates.size();
        vector<int>sol;
        vector<vector<int>>finalsol;

         combi(0,target,candidates,n,sol,finalsol);
         return finalsol;
        
    }
};
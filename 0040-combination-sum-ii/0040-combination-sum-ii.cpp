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
            
        
        combi(index+1,target-candidates[index],candidates,n,sol,finalsol);  

        sol.pop_back(); 
        }
        while (index + 1 < n && candidates[index] == candidates[index + 1]) {  //check for duplicates
        index++;
    }
        combi(index+1,target,candidates,n,sol,finalsol);  //not pick

    }


    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
       sort(candidates.begin(),candidates.end());

       int n=candidates.size();
        vector<int>sol;
        vector<vector<int>>finalsol;

         combi(0,target,candidates,n,sol,finalsol);
         return finalsol;
        
    }
};
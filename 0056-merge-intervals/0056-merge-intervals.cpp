class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        vector<vector<int>>ans;
        sort(intervals.begin(),intervals.end());
        int n=intervals.size();
        int minstart=intervals[0][0];
        int maxend=intervals[0][1];
        for(int i=1;i<n;i++)
        {
            if(intervals[i][0]<=maxend)
            {
                maxend=max(maxend,intervals[i][1]);
            }
            else{
                ans.push_back({minstart,maxend});
                minstart=intervals[i][0];
                maxend=intervals[i][1];

            }
        }
        ans.push_back({minstart,maxend});  //push last interval
        return ans;
        
    }
};
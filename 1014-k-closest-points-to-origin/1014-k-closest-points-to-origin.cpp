class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        pair<int,vector<vector<int>>>p;
        int n=points.size();
        int sqr=0;
        vector<vector<int>>ans;

        priority_queue<pair<int,vector<int>>>pq;

        for(int i=0;i<n;i++)
        {
            sqr=points[i][0]*points[i][0] + points[i][1]*points[i][1];
            pq.push({sqr,{points[i][0],points[i][1]}});
            if(pq.size()>k)
            {
                pq.pop();
            }
        }
        while(!pq.empty())
        {
            pair<int, vector<int>> topEle = pq.top();
            
            ans.push_back(topEle.second);

            pq.pop();

        }
        return ans;
    }
};
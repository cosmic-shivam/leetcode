class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n=arr.size();
        vector<int>pre(n);
        pre[0]=arr[0];
        for(int i=1;i<n;i++)
        {
            pre[i]=pre[i-1]^arr[i];
        }
        vector<int> result;
        for (const auto& query : queries) {
        int L = query[0];
        int R = query[1];
        
        // XOR from arr[L] to arr[R]
        if (L == 0) {
            result.push_back(pre[R]);
        } else {
            result.push_back(pre[R] ^ pre[L-1]);
        }
    }
    
    return result;
    }
};
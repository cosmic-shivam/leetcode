class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char,int>mpp;
        for(auto &st:p){
            mpp[st]++;
        }
        int n=s.size();
        int i=0,j=0,count=mpp.size();
        int k=p.size();
        vector<int>ans;
        while(j<n)
        {
            if(mpp.find(s[j])!=mpp.end())
            {
                mpp[s[j]]--;
                if(mpp[s[j]]==0)
                {
                    count--;
                }
            }
            if(j-i+1<k)
            {
                j++;
            }
            else if(j-i+1==k)
            {
                if(count==0)
                {
                    ans.push_back(i);
                }
                if(mpp.find(s[i])!=mpp.end())
                {
                    mpp[s[i]]++;
                    if(mpp[s[i]]==1)count++;
                }

            i++;
            j++;
            }
           
        }
        return ans;
        
    }
};
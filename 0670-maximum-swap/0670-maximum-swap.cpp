class Solution {
public:
//Take array and store the index of maximum element of right hand side   // better approach O(2n) Space: O(n)

// Optimal Approach : In this we just simply take two index which might get swap , and maxindex and its max Element now just check from backside weather current element is greater than previous then it's our next maxelemnet and store it's index now else this is our position which might get swap . but we want last position which will get swap .
    int maximumSwap(int num) {
        string s=to_string(num);
        int n=s.size();
        char maxEle=s[n-1];
        int maxInd=n-1;
        int swapInd1=-1;
        int swapInd2=-1;
        // vector<int>ans(n,-1);
        // ans[n-1]=n-1 ;
        for(int i=n-2;i>=0;i--)
        {
            if(s[i]-'0'>maxEle-'0')
            {
                maxEle=s[i];
                maxInd=i;
            }
            else if (s[i]-'0'<maxEle-'0'){
                swapInd1=i;
                swapInd2=maxInd;
            }
        }
        if(swapInd1!=-1)
        {
            swap(s[swapInd1],s[swapInd2]);
        }
        // for(int i=0;i<n;i++)
        // {
        //     if(s[i]<s[ans[i]]){
        //         swap(s[i],s[ans[i]]);
        //         break;
        //     }
        // }

        return stoi(s);
        
    }
};
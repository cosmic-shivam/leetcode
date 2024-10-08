class Solution {
public:
    int minSwaps(string s) {
        int extra=0;
        int count=0;
        for(char ans:s)
        {
            if(ans=='[')extra--;
            else extra++;
            count=max(count,extra);


        }
        return (count+1)/2;
        
    }
};
class Solution {
public:
    int minAddToMakeValid(string s) {
        int open=0;
        int close=0;
        int count=0;
        for(char ch:s)
        {
            if(ch=='(')open++;
            else{
                if(open==0){
                    close++;
                }
                else{
                    open--;

                }
                
                

            }
        }
        return open+close;
        
    }
};
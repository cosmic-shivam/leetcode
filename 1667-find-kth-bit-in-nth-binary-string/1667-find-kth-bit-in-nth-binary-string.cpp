class Solution {
public:

    string flp(string str)
    {
        int n=str.size();
        for(int i=0;i<n;i++)
        {
            if(str[i]=='0')str[i]='1';
            else{
                str[i]='0';
            }
            
        }
        return str;
    }
    char findKthBit(int n, int k) {
        string str="0";
        string flip="";
        while(n>0)
        {
            flip=flp(str);
            reverse(flip.begin(),flip.end());
            str=str+'1'+flip;
            n--;
        }
        return str[k-1];
        
    }
};
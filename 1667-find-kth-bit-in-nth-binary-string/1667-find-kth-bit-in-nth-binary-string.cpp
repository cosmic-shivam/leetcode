class Solution {
public:
    //best recursion example
    char bitFind(int len , int k)
    {
        //base case:
        if(len==1)return '0';
        int half=len/2;
        int middle=half+1;
        
        if(k==middle)return '1';   //middle ele is always 1

        else if(k<middle)   //left
        {
            return bitFind(half,k);
        }
        else{ //right
            char ans=bitFind(half,len-k+1);
            return(ans=='0')?'1':'0';  //flip
        }
         
    }
    char findKthBit(int n, int k) {
        int len=pow(2,n)-1;

        return bitFind(len,k);
        
    }
};
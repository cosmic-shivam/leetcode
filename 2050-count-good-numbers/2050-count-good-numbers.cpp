class Solution {
public:
    #define mod 1000000007;

    long long power(long long x,long long y)
    {
        if(y==0)return 1;
        long long ans=power(x,y/2);
        
        if (y % 2 == 0) {
        return (ans * ans) % mod; // Even exponent
    } else {
        return (x * ans * ans) % mod; // Odd exponent
    }
        

    }
    int countGoodNumbers(long long n) {

        long long even=n/2+n%2;
        long long odd=n/2;
        

        return (power(5,even)*power(4,odd))%mod;
        
    }
};
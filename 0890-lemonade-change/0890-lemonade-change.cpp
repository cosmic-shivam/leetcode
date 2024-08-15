class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int count5=0;
        int count10=0;
        int n=bills.size();
        
        for(int i=0;i<n;i++)
        {
            //if(bills[i]==10) && count5==0 
            if(bills[i]==5)
            {
                count5++;
            }
            else if(bills[i]==10)
            {
                count5--;
                count10++;
            }
             else if(bills[i]==20)
            {
                if(count10<=0 && count5>0)
                {
                    count5-=3;

                }
                else{
                count10--;
                count5--;
                }
            }
            if(count5<0)return false;
            if(count10<0)return false;

            
        }
        return true;

        
        
    }
};
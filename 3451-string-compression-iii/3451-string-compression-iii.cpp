class Solution {
public:
    string compressedString(string word) {
        string comp="";
        int n=word.size();
        int count=1;
        for(int i=1;i<n;i++)
        {
            if(word[i]==word[i-1] && count>=9)
            {
                comp+=to_string(count)+word[i];
                count=1;
            }
            else if(word[i]!=word[i-1])
            {
                comp+=to_string(count)+word[i-1];
                count=1;
            }
            else if (word[i]==word[i-1] && count<9)
            {
                count++;
            }
        }
        comp+=to_string(count)+word[n-1];

        return comp;
        
    }
};
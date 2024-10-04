class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(),skill.end());
        int n=skill.size();
        int i=0;
        int j=n-1;
        long long anss=0;
        int check1=skill[i]+skill[j];

        while (i < j) { 
        if(check1!=skill[i]+skill[j])return -1;
        anss += skill[i] * skill[j];  // Multiply the lowest and highest skill
        i++;
        j--;
    }
    return anss;


        
    }
};
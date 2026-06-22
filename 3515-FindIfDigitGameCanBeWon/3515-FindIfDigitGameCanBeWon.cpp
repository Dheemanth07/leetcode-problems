// Last updated: 6/22/2026, 6:28:56 PM
class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        vector<int> v;
        int sum=0,dsum=0;
        for(auto i:nums){
            if(i<10)
                sum+=i;
            else
                v.push_back(i);
        }
        for(auto i:v)
            dsum+=i;
        if(sum>dsum || dsum>sum)
            return true;
        else 
            return false;
    }
};
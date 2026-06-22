// Last updated: 6/22/2026, 6:30:37 PM
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int>rem(60,0);
        int result=0;
        for(auto t:time){
            result+=rem[(60-t%60)%60];
            rem[t%60]++;
        }
        return result;
    }
};
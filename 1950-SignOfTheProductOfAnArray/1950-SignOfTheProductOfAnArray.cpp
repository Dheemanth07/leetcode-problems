// Last updated: 6/22/2026, 6:29:37 PM
class Solution {
public:
    int arraySign(vector<int>& nums) {
        int ncnt=0,pcnt=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                return 0;
                break;
            }
            else if(nums[i]<0)
                ncnt++;
        }
        if(ncnt%2==0)
            return 1;
        else 
            return -1;
    }
};
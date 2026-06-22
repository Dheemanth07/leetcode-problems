// Last updated: 6/22/2026, 6:29:58 PM
class Solution {
public:
    int xorOperation(int n, int start) {
        vector<int> nums(n);
        for(int i=0;i<n;i++)
            nums[i]=start+2*i;
        int xsum=nums[0];
        for(int i=1;i<nums.size();i++)
            xsum^=nums[i];
        return xsum;
    }
};
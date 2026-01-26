// Last updated: 1/26/2026, 6:34:08 PM
1class Solution {
2public:
3    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
4        if(nums.empty()) return {};
5        vector<int>res;
6        for(int i=0;i<nums.size();i++){
7            int count=0;
8            for(int j=0;j<nums.size();j++){
9                if(i==j) continue;
10                if(nums[j]<nums[i]) count++;
11            }
12            res.push_back(count);
13        }
14        return res;
15    }
16};
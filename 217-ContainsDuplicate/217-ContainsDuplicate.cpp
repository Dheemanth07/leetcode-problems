// Last updated: 1/25/2026, 1:31:06 PM
1class Solution {
2public:
3    bool containsDuplicate(vector<int>& nums) {
4        unordered_set<int> st;
5        for(int num:nums){
6            if(st.count(num))
7                return true;
8            st.insert(num);
9        }
10        return false;
11    }
12};
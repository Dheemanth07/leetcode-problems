// Last updated: 7/13/2026, 2:30:01 PM
1class Solution {
2public:
3    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
4        vector<int> v(nums1.size(), -1);
5        unordered_map<int, int> mp;
6
7        for (int i = 0; i < nums2.size(); i++)
8            mp[nums2[i]] = i;
9
10        for (int i = 0; i < nums1.size(); i++) {
11            int n = mp[nums1[i]];
12
13            for (int j = n; j < nums2.size(); j++) {
14                if (nums2[j] > nums1[i]) {
15                    v[i] = nums2[j];
16                    break;
17                }
18            }
19        }
20
21        return v;
22    }
23};
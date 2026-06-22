// Last updated: 6/22/2026, 7:39:51 PM
1class Solution {
2public:
3    vector<int> productExceptSelf(vector<int>& nums) {
4        int n = nums.size();
5        vector<int> answer(n, 1);
6
7        int leftproduct = 1;
8
9        for (int i = 0; i < n; i++) {
10            answer[i] = leftproduct;
11            leftproduct *= nums[i];
12        }
13
14        int rightproduct = 1;
15
16        for (int i = n - 1; i >= 0; i--) {
17            answer[i] *= rightproduct;
18            rightproduct *= nums[i];
19        }
20
21        return answer;
22    }
23};
// Last updated: 4/3/2026, 9:49:55 PM
1class Solution {
2public:
3    vector<int> productExceptSelf(vector<int>& nums) {
4        int n = nums.size();
5        vector<int> answer(n, 1);
6        int leftproduct = 1;
7        for (int i = 0; i < n; i++) {
8            answer[i] = leftproduct;
9            leftproduct *= nums[i];
10        }
11        int rightproduct = 1;
12        for (int i = n - 1; i >= 0; i--) {
13            answer[i] *= rightproduct;
14            rightproduct *= nums[i];
15        }
16        return answer;
17    }
18};
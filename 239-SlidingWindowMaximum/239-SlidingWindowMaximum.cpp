// Last updated: 2/4/2026, 8:09:02 PM
1class Solution {
2public:
3    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
4        if (nums.empty())
5            return {};
6        int n = nums.size();
7        deque<int> dq;
8        vector<int> res;
9        for (int i = 0; i < n; i++) {
10            if (!dq.empty() && dq.front() == i - k)
11                dq.pop_front();
12            while (!dq.empty() && nums[i] > nums[dq.back()])
13                dq.pop_back();
14            dq.push_back(i);
15            if (i >= k - 1)
16                res.push_back(nums[dq.front()]);
17        }
18        return res;
19    }
20};
21
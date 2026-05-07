// Last updated: 5/7/2026, 8:25:52 AM
1class Solution {
2public:
3    vector<int> dailyTemperatures(vector<int>& temperatures) {
4        int n = temperatures.size();
5        vector<int> ans(n, 0);
6        stack<int> st;
7        for (int i = 0; i < n; i++) {
8            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
9                int prev = st.top();
10                st.pop();
11                ans[prev] = i - prev;
12            }
13            st.push(i);
14        }
15        return ans;
16    }
17};
// Last updated: 6/27/2026, 11:36:56 AM
1class Solution {
2public:
3    vector<int> dailyTemperatures(vector<int>& temperatures) {
4        int n = temperatures.size();
5
6        vector<int> ans(n, 0);
7        stack<int> st;
8
9        for (int i = 0; i < n; i++) {
10            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
11                int prev = st.top();
12                st.pop();
13                ans[prev] = i - prev;
14            }
15
16            st.push(i);
17        }
18
19        return ans;
20    }
21};
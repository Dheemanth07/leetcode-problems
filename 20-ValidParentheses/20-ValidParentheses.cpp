// Last updated: 2/4/2026, 9:30:09 PM
1class Solution {
2public:
3    bool isValid(string s) {
4        stack<char> st;
5        for (char c : s) {
6            if (c == '(' || c == '[' || c == '{')
7                st.push(c);
8            else {
9                if (st.empty())
10                    return false;
11                if (c == ')' && st.top() != '(' ||
12                    c == ']' && st.top() != '[' || c == '}' && st.top() != '{')
13                    return false;
14                st.pop();
15            }
16        }
17        return st.empty();
18    }
19};
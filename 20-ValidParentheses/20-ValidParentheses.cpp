// Last updated: 6/27/2026, 10:44:17 AM
1class Solution {
2public:
3    bool isValid(string s) {
4        stack<char> st;
5
6        for (char c : s) {
7            if (c == '(' || c == '[' || c == '{')
8                st.push(c);
9            else {
10                if (st.empty())
11                    return false;
12                if (c == ')' && st.top() != '(' ||
13                    c == ']' && st.top() != '[' || c == '}' && st.top() != '{')
14                    return false;
15
16                st.pop();
17            }
18        }
19
20        return st.empty();
21    }
22};
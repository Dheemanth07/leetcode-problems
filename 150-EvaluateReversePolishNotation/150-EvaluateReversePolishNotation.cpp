// Last updated: 2/5/2026, 7:17:14 AM
1class Solution {
2public:
3    int evalRPN(vector<string>& tokens) {
4        stack<long> st;
5        for (string& s : tokens) {
6            if (s == "+" || s == "-" || s == "*" || s == "/") {
7                long first = st.top();
8                st.pop();
9                long second = st.top();
10                st.pop();
11                if (s == "+")
12                    st.push(second + first);
13                else if (s == "-")
14                    st.push(second - first);
15                else if (s == "*")
16                    st.push(second * first);
17                else if (s == "/")
18                    st.push(second / first);
19            } else
20                st.push(stol(s));
21        }
22        return (int)st.top();
23    }
24};
25
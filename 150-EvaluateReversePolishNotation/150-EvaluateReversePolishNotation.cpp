// Last updated: 6/27/2026, 10:50:48 AM
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
11
12                if (s == "+")
13                    st.push(second + first);
14                else if (s == "-")
15                    st.push(second - first);
16                else if (s == "*")
17                    st.push(second * first);
18                else if (s == "/")
19                    st.push(second / first);
20            } else
21                st.push(stol(s));
22        }
23
24        return (int)st.top();
25    }
26};
27
// Last updated: 5/7/2026, 7:31:59 AM
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (const string& t : tokens) {
            if (t == "+" || t == "-" || t == "*" || t == "/") {
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();

                if (t == "+") st.push(a + b);
                else if (t == "-") st.push(a - b);
                else if (t == "*") st.push(a * b);
                else st.push(a / b); // truncates toward 0
            } else {
                st.push(stoi(t));
            }
        }
        return st.top();
    }
};
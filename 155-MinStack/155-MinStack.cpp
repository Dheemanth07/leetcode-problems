// Last updated: 2/4/2026, 9:30:46 PM
1class MinStack {
2    stack<int> st, minst;
3
4public:
5    MinStack() {}
6
7    void push(int val) {
8        st.push(val);
9        if (minst.empty())
10            minst.push(val);
11        else
12            minst.push(min(val, minst.top()));
13    }
14
15    void pop() {
16        st.pop();
17        minst.pop();
18    }
19
20    int top() { return st.top(); }
21
22    int getMin() { return minst.top(); }
23};
24
25/**
26 * Your MinStack object will be instantiated and called as such:
27 * MinStack* obj = new MinStack();
28 * obj->push(val);
29 * obj->pop();
30 * int param_3 = obj->top();
31 * int param_4 = obj->getMin();
32 */
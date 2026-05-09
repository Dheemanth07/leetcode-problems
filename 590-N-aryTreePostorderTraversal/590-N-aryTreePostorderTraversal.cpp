// Last updated: 5/9/2026, 11:23:53 AM
1/*
2// Definition for a Node.
3class Node {
4public:
5    int val;
6    vector<Node*> children;
7
8    Node() {}
9
10    Node(int _val) {
11        val = _val;
12    }
13
14    Node(int _val, vector<Node*> _children) {
15        val = _val;
16        children = _children;
17    }
18};
19*/
20
21class Solution {
22public:
23    vector<int> postorder(Node* root) {
24        if (root == nullptr)
25            return {};
26
27        vector<int> result;
28        stack<Node*> st;
29        st.push(root);
30
31        while (!st.empty()) {
32            Node* curr = st.top();
33            st.pop();
34
35            // "Process" the root immediately (Pre-order style)
36            result.push_back(curr->val);
37
38            // Push children to the stack from Left to Right.
39            // Because it's a stack (LIFO), they will be popped Right to Left!
40            for (Node* child : curr->children)
41                if (child)
42                    st.push(child);
43        }
44
45        // Right now our array is: Root -> Rightmost -> ... -> Leftmost
46        // Reverse it to get true Postorder: Leftmost -> ... -> Rightmost ->
47        // Root!
48        reverse(result.begin(), result.end());
49
50        return result;
51    }
52};
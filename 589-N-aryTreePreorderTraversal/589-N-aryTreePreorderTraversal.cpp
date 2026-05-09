// Last updated: 5/9/2026, 11:33:41 AM
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
23    vector<int> preorder(Node* root) {
24        if (root == nullptr)
25            return {};
26
27        vector<int> result;
28        stack<Node*> st;
29        st.push(root);
30
31        while (!st.empty()) {
32            // Grab the top node and process it immediately
33            Node* curr = st.top();
34            st.pop();
35            result.push_back(curr->val);
36
37            // THE TRICK: Push children from RIGHT to LEFT
38            // This ensures the Leftmost child ends up on top of the stack!
39            for (int i = curr->children.size() - 1; i >= 0; i--) {
40                if (curr->children[i] != nullptr) {
41                    st.push(curr->children[i]);
42                }
43            }
44        }
45
46        return result;
47    }
48};
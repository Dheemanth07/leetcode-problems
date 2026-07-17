// Last updated: 7/17/2026, 2:02:08 PM
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> postorder(Node* root) {
        if (root == nullptr)
            return {};

        vector<int> result;
        stack<Node*> st;
        st.push(root);

        while (!st.empty()) {
            Node* curr = st.top();
            st.pop();

            // "Process" the root immediately (Pre-order style)
            result.push_back(curr->val);

            // Push children to the stack from Left to Right.
            // Because it's a stack (LIFO), they will be popped Right to Left!
            for (Node* child : curr->children)
                if (child)
                    st.push(child);
        }

        // Right now our array is: Root -> Rightmost -> ... -> Leftmost
        // Reverse it to get true Postorder: Leftmost -> ... -> Rightmost ->
        // Root!
        reverse(result.begin(), result.end());

        return result;
    }
};
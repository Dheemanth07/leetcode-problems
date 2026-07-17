// Last updated: 7/17/2026, 2:02:10 PM
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
    vector<int> preorder(Node* root) {
        if (root == nullptr)
            return {};

        vector<int> result;
        stack<Node*> st;
        st.push(root);

        while (!st.empty()) {
            // Grab the top node and process it immediately
            Node* curr = st.top();
            st.pop();
            result.push_back(curr->val);

            // THE TRICK: Push children from RIGHT to LEFT
            // This ensures the Leftmost child ends up on top of the stack!
            for (int i = curr->children.size() - 1; i >= 0; i--)
                if (curr->children[i] != nullptr)
                    st.push(curr->children[i]);
                
        }

        return result;
    }
};
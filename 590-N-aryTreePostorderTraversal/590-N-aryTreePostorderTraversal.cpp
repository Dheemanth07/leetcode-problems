// Last updated: 5/9/2026, 11:10:58 AM
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
22private:
23    // Our recursive helper function
24    void traverse(Node* root, vector<int>& result) {
25        // 1. Base Case: If the node doesn't exist, stop.
26        if (root == nullptr) {
27            return;
28        }
29
30        // 2. The Leap of Faith: Tell ALL children to process themselves FIRST
31        for (Node* child : root->children) {
32            traverse(child, result);
33        }
34
35        // 3. The Work: Now that the loop is over, all my children are done.
36        // It is finally my turn to be added to the list!
37        result.push_back(root->val);
38    }
39
40public:
41    vector<int> postorder(Node* root) {
42        vector<int> result;
43        traverse(root, result); // Kick off the recursion
44        return result;
45    }
46};
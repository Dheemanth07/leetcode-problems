// Last updated: 7/3/2026, 1:24:19 PM
1class Solution {
2public:
3    vector<int> inorderTraversal(TreeNode* root) {
4        vector<int> result;
5        TreeNode* cur = root;
6
7        while (cur) {
8            // Rule 1: No left child
9            if (!cur->left) {
10                result.push_back(cur->val);
11                cur = cur->right;
12            } else {
13                // Find the inorder predecessor
14                TreeNode* predecessor = cur->left;
15                while (predecessor->right && predecessor->right != cur)
16                    predecessor = predecessor->right;
17
18                // Rule 2: Build the thread
19                if (!predecessor->right) {
20                    predecessor->right = cur;
21                    cur = cur->left;
22                }
23                // Rule 3: Destroy the thread and collect the value
24                else {
25                    predecessor->right = nullptr;
26                    result.push_back(cur->val);
27                    cur = cur->right;
28                }
29            }
30        }
31
32        return result;
33    }
34};
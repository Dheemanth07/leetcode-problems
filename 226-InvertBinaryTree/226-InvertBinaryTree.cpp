// Last updated: 2/13/2026, 8:52:20 PM
1/**
2 * Definition for a binary tree node.
3 * struct TreeNode {
4 *     int val;
5 *     TreeNode *left;
6 *     TreeNode *right;
7 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
8 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
9 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
10 * right(right) {}
11 * };
12 */
13class Solution {
14public:
15    TreeNode* invertTree(TreeNode* root) {
16        if (!root)
17            return 0;
18        TreeNode* node = new TreeNode(root->val);
19        node->left = invertTree(root->right);
20        node->right = invertTree(root->left);
21        return node;
22    }
23};
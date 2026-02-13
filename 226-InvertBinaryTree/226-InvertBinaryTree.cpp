// Last updated: 2/13/2026, 8:53:43 PM
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
17            return nullptr;
18        swap(root->left,root->right);
19        invertTree(root->left);
20        invertTree(root->right);
21        return root;
22    }
23};
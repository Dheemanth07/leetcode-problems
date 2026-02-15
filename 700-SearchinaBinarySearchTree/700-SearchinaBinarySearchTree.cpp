// Last updated: 2/15/2026, 6:24:45 PM
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
15    TreeNode* searchBST(TreeNode* root, int val) {
16        if (!root)
17            return nullptr;
18        if (val < root->val)
19            return searchBST(root->left, val);
20        if (val > root->val)
21            return searchBST(root->right, val);
22        return root;
23    }
24};
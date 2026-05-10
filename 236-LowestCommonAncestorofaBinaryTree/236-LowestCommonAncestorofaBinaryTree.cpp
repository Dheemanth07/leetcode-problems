// Last updated: 5/10/2026, 4:21:03 PM
1/**
2 * Definition for a binary tree node.
3 * struct TreeNode {
4 *     int val;
5 *     TreeNode *left;
6 *     TreeNode *right;
7 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
8 * };
9 */
10class Solution {
11public:
12    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
13        if (!root || root == p || root == q)
14            return root;
15
16        TreeNode* leftReport = lowestCommonAncestor(root->left, p, q);
17        TreeNode* rightReport = lowestCommonAncestor(root->right, p, q);
18
19        if (leftReport && rightReport)
20            return root;
21
22        return leftReport ? leftReport : rightReport;
23    }
24};
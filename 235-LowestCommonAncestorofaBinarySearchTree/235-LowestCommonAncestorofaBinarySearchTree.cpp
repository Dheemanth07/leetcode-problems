// Last updated: 2/15/2026, 5:26:45 PM
1/**
2 * Definition for a binary tree node.
3 * struct TreeNode {
4 *     int val;
5 *     TreeNode *left;
6 *     TreeNode *right;
7 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
8 * };
9 */
10
11class Solution {
12public:
13    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
14        if (!root)
15            return 0;
16        if (p->val < root->val && q->val < root->val)
17            return lowestCommonAncestor(root->left, p, q);
18        if (p->val > root->val && q->val > root->val)
19            return lowestCommonAncestor(root->right, p, q);
20        return root;
21    }
22};
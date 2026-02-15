// Last updated: 2/15/2026, 5:34:09 PM
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
14        while (root) {
15            if (p->val < root->val && q->val < root->val)
16                root = root->left;
17            else if (p->val > root->val && q->val > root->val)
18                root = root->right;
19            else
20                return root; // split point
21        }
22        return nullptr;
23    }
24};
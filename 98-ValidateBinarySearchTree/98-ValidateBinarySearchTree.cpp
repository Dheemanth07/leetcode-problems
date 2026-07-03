// Last updated: 7/3/2026, 4:46:17 PM
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
13
14class Solution {
15public:
16    bool validate(TreeNode* root, long long minval, long long maxval) {
17        if (!root)
18            return true;
19        if (root->val <= minval || root->val >= maxval)
20            return false;
21        return validate(root->left, minval, root->val) &&
22               validate(root->right, root->val, maxval);
23    }
24
25    bool isValidBST(TreeNode* root) {
26        return validate(root, LLONG_MIN, LLONG_MAX);
27    }
28};
29
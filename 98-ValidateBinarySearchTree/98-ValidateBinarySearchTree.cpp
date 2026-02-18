// Last updated: 2/18/2026, 8:25:19 PM
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
15    bool validate(TreeNode* root, long long minval, long long maxval) {
16        if (!root)
17            return true;
18        if (root->val <= minval || root->val >= maxval)
19            return false;
20        return validate(root->left, minval, root->val) &&
21               validate(root->right, root->val, maxval);
22    }
23
24    bool isValidBST(TreeNode* root) {
25        return validate(root, LLONG_MIN, LLONG_MAX);
26    }
27};
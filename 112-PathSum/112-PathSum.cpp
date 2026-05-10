// Last updated: 5/10/2026, 9:15:21 AM
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
15    bool hasPathSum(TreeNode* root, int targetSum) {
16        if (!root)
17            return false;
18
19        if (!root->left && !root->right)
20            return targetSum == root->val;
21
22        int remainingSum = targetSum - root->val;
23
24        return hasPathSum(root->left, remainingSum) ||
25               hasPathSum(root->right, remainingSum);
26    }
27};
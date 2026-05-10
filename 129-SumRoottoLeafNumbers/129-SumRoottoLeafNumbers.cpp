// Last updated: 5/10/2026, 10:38:17 AM
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
15    int sumNumbers(TreeNode* root) { return dfs(root, 0); }
16
17    int dfs(TreeNode* root, int currentSum) {
18        if (!root)
19            return 0;
20
21        currentSum = (currentSum * 10) + root->val;
22
23        if (!root->left && !root->right)
24            return currentSum;
25
26        return dfs(root->left, currentSum) + dfs(root->right, currentSum);
27    }
28};
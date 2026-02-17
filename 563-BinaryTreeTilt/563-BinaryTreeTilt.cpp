// Last updated: 2/17/2026, 7:49:13 PM
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
15    int tilt = 0;
16
17    int dfs(TreeNode* root) {
18        if (!root)
19            return 0;
20        int left = dfs(root->left);
21        int right = dfs(root->right);
22        tilt += abs(left - right);
23        return root->val + left + right;
24    }
25
26    int findTilt(TreeNode* root) {
27        dfs(root);
28        return tilt;
29    }
30};
// Last updated: 2/14/2026, 7:55:48 PM
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
15    int height(TreeNode* root) {
16        if (!root)
17            return 0;
18        int left = height(root->left);
19        int right = height(root->right);
20        return 1 + max(left, right);
21    }
22
23    bool isBalanced(TreeNode* root) {
24        if (!root)
25            return true;
26        int left = height(root->left);
27        int right = height(root->right);
28        if (abs(left - right) > 1)
29            return false;
30        return isBalanced(root->left) && isBalanced(root->right);
31    }
32};
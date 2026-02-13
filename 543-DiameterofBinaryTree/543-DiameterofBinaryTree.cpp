// Last updated: 2/13/2026, 9:28:27 PM
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
15    int diameterOfBinaryTree(TreeNode* root) {
16        int diameter = 0;
17        height(root, diameter);
18        return diameter;
19    }
20    int height(TreeNode* root, int& diameter) {
21        if (!root)
22            return 0;
23        int left = height(root->left, diameter);
24        int right = height(root->right, diameter);
25        diameter = max(diameter, left + right);
26        return 1 + max(left, right);
27    }
28};
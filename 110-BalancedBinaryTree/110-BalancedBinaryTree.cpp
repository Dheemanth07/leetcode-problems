// Last updated: 2/14/2026, 8:06:34 PM
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
15    int checkHeight(TreeNode* root) {
16        if (!root)
17            return 0;
18
19        int left = checkHeight(root->left);
20        if (left == -1)
21            return -1;
22
23        int right = checkHeight(root->right);
24        if (right == -1)
25            return -1;
26
27        if (abs(left - right) > 1)
28            return -1;
29
30        return 1 + max(left, right);
31    }
32
33    bool isBalanced(TreeNode* root) { return checkHeight(root) != -1; }
34};
// Last updated: 7/2/2026, 7:29:26 PM
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
16    int diameter = 0;
17    int maxHeight(TreeNode* root) {
18        if (!root)
19            return 0;
20        int leftHeight = maxHeight(root->left);
21        int rightHeight = maxHeight(root->right);
22        diameter = max(diameter, leftHeight + rightHeight);
23        return 1 + max(leftHeight, rightHeight);
24    }
25
26    int diameterOfBinaryTree(TreeNode* root) {
27        maxHeight(root);
28        return diameter;
29    }
30};
31
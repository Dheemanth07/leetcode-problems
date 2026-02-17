// Last updated: 2/17/2026, 8:06:39 PM
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
15    bool isMirror(TreeNode* t1, TreeNode* t2) {
16        if (!t1 && !t2)
17            return true;
18        if (!t1 || !t2)
19            return false;
20
21        if (t1->val != t2->val)
22            return false;
23
24        return isMirror(t1->left, t2->right) && isMirror(t1->right, t2->left);
25    }
26
27    bool isSymmetric(TreeNode* root) {
28        if (!root)
29            return true;
30        return isMirror(root->left, root->right);
31    }
32};
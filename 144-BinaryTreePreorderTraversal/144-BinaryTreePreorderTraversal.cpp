// Last updated: 7/3/2026, 10:33:25 AM
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
14    vector<int> res;
15
16public:
17    vector<int> preorderTraversal(TreeNode* root) {
18        if (!root)
19            return {};
20        res.push_back(root->val);
21        preorderTraversal(root->left);
22        preorderTraversal(root->right);
23        return res;
24    }
25};
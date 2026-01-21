// Last updated: 1/21/2026, 10:21:21 PM
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
15    vector<string> res;
16
17    void dfs(TreeNode* root, string path) {
18        if (!root)
19            return;
20        path += to_string(root->val);
21        if (!root->left && !root->right) {
22            res.push_back(path);
23            return;
24        }
25        path += "->";
26        dfs(root->left, path);
27        dfs(root->right, path);
28    }
29
30    vector<string> binaryTreePaths(TreeNode* root) {
31        dfs(root, "");
32        return res;
33    }
34};
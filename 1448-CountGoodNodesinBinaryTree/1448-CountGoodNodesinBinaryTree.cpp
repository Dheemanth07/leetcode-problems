// Last updated: 2/18/2026, 4:16:13 PM
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
16    int count = 0;
17
18    void dfs(TreeNode* root, int maxSoFar) {
19        if (!root)
20            return;
21        if (root->val >= maxSoFar) {
22            count++;
23            maxSoFar = root->val;
24        }
25        dfs(root->left, maxSoFar);
26        dfs(root->right, maxSoFar);
27    }
28
29    int goodNodes(TreeNode* root) {
30        dfs(root, root->val);
31        return count;
32    }
33};
34
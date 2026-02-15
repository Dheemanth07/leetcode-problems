// Last updated: 2/15/2026, 5:55:48 PM
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
15    vector<vector<int>> levelOrder(TreeNode* root) {
16        vector<vector<int>> res;
17        if (!root)
18            return res;
19        queue<TreeNode*> q;
20        q.push(root);
21        while (!q.empty()) {
22            int size = q.size();
23            vector<int> level;
24            for (int i = 0; i < size; i++) {
25                TreeNode* node = q.front();
26                q.pop();
27                level.push_back(node->val);
28                if (node->left)
29                    q.push(node->left);
30                if (node->right)
31                    q.push(node->right);
32            }
33            res.push_back(level);
34        }
35        return res;
36    }
37};
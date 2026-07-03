// Last updated: 7/3/2026, 2:07:32 PM
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
15    vector<int> rightSideView(TreeNode* root) {
16        if (!root)
17            return {};
18
19        vector<int> res;
20
21        queue<TreeNode*> q;
22        q.push(root);
23
24        while (!q.empty()) {
25            int level = q.size();
26
27            for (int i = 0; i < level; i++) {
28                TreeNode* node = q.front();
29                q.pop();
30
31                if (i == level - 1)
32                    res.push_back(node->val);
33                if (node->left)
34                    q.push(node->left);
35                if (node->right)
36                    q.push(node->right);
37            }
38        }
39
40        return res;
41    }
42};
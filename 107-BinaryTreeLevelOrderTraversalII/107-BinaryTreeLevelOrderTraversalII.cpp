// Last updated: 7/3/2026, 1:51:26 PM
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
15    vector<vector<int>> levelOrderBottom(TreeNode* root) {
16        vector<vector<int>> res;
17        if (!root)
18            return res;
19
20        queue<TreeNode*> q;
21        q.push(root);
22
23        while (!q.empty()) {
24            int size = q.size();
25            vector<int> level;
26
27            for (int i = 0; i < size; i++) {
28                TreeNode* node = q.front();
29                q.pop();
30
31                level.push_back(node->val);
32                if (node->left)
33                    q.push(node->left);
34                if (node->right)
35                    q.push(node->right);
36            }
37
38            res.insert(res.begin(), level);
39        }
40
41        return res;
42    }
43};
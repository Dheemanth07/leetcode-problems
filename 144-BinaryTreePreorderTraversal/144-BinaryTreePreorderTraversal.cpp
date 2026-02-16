// Last updated: 2/16/2026, 2:22:40 PM
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
15    vector<int> preorderTraversal(TreeNode* root) {
16        vector<int> res;
17        TreeNode* cur = root;
18        while (cur) {
19            if (!cur->left) {
20                res.push_back(cur->val);
21                cur = cur->right;
22            } else {
23                TreeNode* pred = cur->left;
24                while (pred->right && pred->right != cur)
25                    pred = pred->right;
26                if (!pred->right) {
27                    res.push_back(cur->val);
28                    pred->right = cur;
29                    cur = cur->left;
30                } else {
31                    pred->right = NULL;
32                    cur = cur->right;
33                }
34            }
35        }
36        return res;
37    }
38};
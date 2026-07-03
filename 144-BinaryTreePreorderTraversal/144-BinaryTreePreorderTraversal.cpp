// Last updated: 7/3/2026, 1:26:45 PM
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
14
15public:
16    vector<int> preorderTraversal(TreeNode* root) {
17        vector<int> res;
18        TreeNode* curr = root;
19
20        while (curr) {
21            if (!curr->left) {
22                res.push_back(curr->val);
23                curr = curr->right;
24            } else {
25                TreeNode* pred = curr->left;
26                while (pred->right && pred->right != curr)
27                    pred = pred->right;
28
29                if (!pred->right) {
30                    res.push_back(curr->val); // visit before creating thread
31                    pred->right = curr;
32                    curr = curr->left;
33                } else {
34                    pred->right = nullptr; // remove thread
35                    curr = curr->right;
36                }
37            }
38        }
39        return res;
40    }
41};
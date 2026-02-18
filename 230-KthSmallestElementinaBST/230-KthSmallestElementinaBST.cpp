// Last updated: 2/18/2026, 8:51:02 PM
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
17    int ans = 0;
18
19    void inorder(TreeNode* root, int k) {
20        if (!root)
21            return;
22
23        inorder(root->left, k);
24
25        count++;
26        if (count == k) {
27            ans = root->val;
28            return;
29        }
30
31        inorder(root->right, k);
32    }
33
34    int kthSmallest(TreeNode* root, int k) {
35        inorder(root, k);
36        return ans;
37    }
38};
39
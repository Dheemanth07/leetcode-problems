// Last updated: 2/15/2026, 6:52:31 PM
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
15    TreeNode* findMin(TreeNode* root) {
16        while (root->left)
17            root = root->left;
18        return root;
19    }
20
21    TreeNode* deleteNode(TreeNode* root, int key) {
22        if (!root)
23            return nullptr;
24        if (key < root->val)
25            root->left = deleteNode(root->left, key);
26        else if (key > root->val)
27            root->right = deleteNode(root->right, key);
28        else {
29            if (!root->left && !root->right)
30                return nullptr;
31            if (!root->left)
32                return root->right;
33            if (!root->right)
34                return root->left;
35            TreeNode* successor = findMin(root->right);
36            root->val = successor->val;
37            root->right = deleteNode(root->right, successor->val);
38        }
39        return root;
40    }
41};
// Last updated: 2/16/2026, 3:27:38 PM
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
15
16    void preorder(TreeNode* root, vector<int> &res){
17        if(!root) return;
18        res.push_back(root->val);
19        preorder(root->left,res);
20        preorder(root->right,res);
21    }
22
23    vector<int> preorderTraversal(TreeNode* root) {
24        vector<int>res;
25        preorder(root,res);
26        return res;
27    }
28
29    
30};
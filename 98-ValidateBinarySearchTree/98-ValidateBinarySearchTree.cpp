// Last updated: 1/15/2026, 10:59:16 PM
1/**
2 * Definition for a binary tree node.
3 * struct TreeNode {
4 *     int val;
5 *     TreeNode *left;
6 *     TreeNode *right;
7 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
8 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
9 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
10 * };
11 */
12class Solution {
13public:
14    bool validate(TreeNode* root,long long minval,long long maxval){
15        if(!root) return true;
16        if(root->val<=minval || root->val>=maxval) return false;
17        return validate(root->left,minval,root->val) && validate(root->right,root->val,maxval);
18    }
19
20    bool isValidBST(TreeNode* root) {
21        return validate(root,LLONG_MIN,LLONG_MAX);
22    }
23};
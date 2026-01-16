// Last updated: 1/16/2026, 11:56:57 PM
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
12
13class Solution {
14    unordered_map<int,int>mp;
15    int preIndex=0;
16    TreeNode* build(vector<int>&preorder,int inStart,int inEnd){
17        if(inStart>inEnd) return nullptr;
18        int rootval=preorder[preIndex++];
19        TreeNode* root=new TreeNode(rootval);
20        int mid=mp[rootval];
21        root->left=build(preorder,inStart,mid-1);
22        root->right=build(preorder,mid+1,inEnd);
23        return root;
24    }
25
26public:
27    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
28        for(int i=0;i<inorder.size();i++)
29            mp[inorder[i]]=i;
30        return build(preorder,0,inorder.size()-1);
31    }
32};
33
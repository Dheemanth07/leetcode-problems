// Last updated: 2/19/2026, 4:57:28 PM
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
14    unordered_map<int,int>mp;
15    int postIdx;
16    
17    TreeNode* build(vector<int>& postorder,int inStart, int inEnd ){
18        if(inStart>inEnd) return nullptr;
19        int rootVal=postorder[postIdx--];
20        TreeNode* node = new TreeNode(rootVal);
21        int mid=mp[rootVal];
22        node->right=build(postorder,mid+1,inEnd);
23        node->left=build(postorder,inStart,mid-1);
24        return node;
25    }
26
27    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
28        for(int i=0;i<inorder.size();i++)
29            mp[inorder[i]]=i;
30        postIdx=postorder.size()-1;
31        return build(postorder,0,inorder.size()-1);
32    }   
33};
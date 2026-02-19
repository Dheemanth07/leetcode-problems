// Last updated: 2/19/2026, 4:33:50 PM
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
15    unordered_map<int, int> mp;
16    int preIndex = 0;
17    TreeNode* build(vector<int>& preorder, int inStart, int inEnd) {
18        if (inStart > inEnd)
19            return nullptr;
20        int rootval = preorder[preIndex++];
21        TreeNode* root = new TreeNode(rootval);
22        int mid = mp[rootval];
23        root->left = build(preorder, inStart, mid - 1);
24        root->right = build(preorder, mid + 1, inEnd);
25        return root;
26    }
27
28public:
29    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
30        for (int i = 0; i < inorder.size(); i++)
31            mp[inorder[i]] = i;
32        return build(preorder, 0, inorder.size() - 1);
33    }
34};
35
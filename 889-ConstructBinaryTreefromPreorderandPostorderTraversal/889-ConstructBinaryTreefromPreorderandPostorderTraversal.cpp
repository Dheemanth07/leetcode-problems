// Last updated: 2/19/2026, 6:16:29 PM
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
15    unordered_map<int, int> mp;
16    int preIdx = 0;
17
18    TreeNode* build(vector<int>& preorder, vector<int>& postorder, int left,
19                    int right) {
20        if (left > right)
21            return nullptr;
22        TreeNode* node = new TreeNode(preorder[preIdx++]);
23        if (left == right)
24            return node;
25        int leftRootVal = preorder[preIdx];
26        int mid = mp[leftRootVal];
27        node->left = build(preorder, postorder, left, mid);
28        node->right = build(preorder, postorder, mid + 1, right-1);
29        return node;
30    }
31
32    TreeNode* constructFromPrePost(vector<int>& preorder,
33                                   vector<int>& postorder) {
34        for (int i = 0; i < postorder.size(); i++)
35            mp[postorder[i]] = i;
36        return build(preorder, postorder, 0, postorder.size() - 1);
37    }
38};
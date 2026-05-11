// Last updated: 5/11/2026, 4:45:04 PM
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
22
23        TreeNode* node = new TreeNode(preorder[preIdx++]);
24
25        if (left == right)
26            return node;
27
28        int leftRootVal = preorder[preIdx];
29
30        int mid = mp[leftRootVal];
31        node->left = build(preorder, postorder, left, mid);
32        node->right = build(preorder, postorder, mid + 1, right - 1);
33
34        return node;
35    }
36
37    TreeNode* constructFromPrePost(vector<int>& preorder,
38                                   vector<int>& postorder) {
39
40        for (int i = 0; i < postorder.size(); i++)
41            mp[postorder[i]] = i;
42
43        return build(preorder, postorder, 0, postorder.size() - 1);
44    }
45};
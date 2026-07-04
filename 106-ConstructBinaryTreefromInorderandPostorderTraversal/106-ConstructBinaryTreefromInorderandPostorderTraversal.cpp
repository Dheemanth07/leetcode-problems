// Last updated: 7/4/2026, 10:17:35 PM
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
14private:
15    int postorderIndex;
16    unordered_map<int, int> inorderMap;
17
18    TreeNode* build(vector<int>& postorder, int left, int right) {
19        if (left > right)
20            return nullptr;
21
22        // 1. The Detective reads backwards
23        int rootVal = postorder[postorderIndex--];
24        TreeNode* root = new TreeNode(rootVal);
25
26        // 2. The Map splits the neighborhoods
27        int mid = inorderMap[rootVal];
28
29        // 3. THE LEAP OF FAITH (RIGHT FIRST!)
30        // Because we are reading postorder backwards, the right child's
31        // root is guaranteed to be the very next number we pop!
32        root->right = build(postorder, mid + 1, right);
33        root->left = build(postorder, left, mid - 1);
34
35        return root;
36    }
37
38public:
39    TreeNode* buildTree(vector<int>& inorder,
40                        vector<int>& postorder) {
41        postorderIndex = postorder.size() - 1; // Start at the absolute end
42        for (int i = 0; i < inorder.size(); i++)
43            inorderMap[inorder[i]] = i;
44
45        return build(postorder, 0, inorder.size() - 1);
46    }
47};
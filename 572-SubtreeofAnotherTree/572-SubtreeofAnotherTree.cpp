// Last updated: 1/15/2026, 12:19:18 PM
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
15    bool isSametree(TreeNode* p, TreeNode* q) {
16        if (!p && !q)
17            return true;
18        if (!p || !q)
19            return false;
20        return (p->val == q->val) && isSametree(p->left, q->left) &&
21               isSametree(p->right, q->right);
22    }
23
24    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
25        if (!root)
26            return false;
27        if (isSametree(root, subRoot))
28            return true;
29        return isSubtree(root->left, subRoot) ||
30               isSubtree(root->right, subRoot);
31    }
32};
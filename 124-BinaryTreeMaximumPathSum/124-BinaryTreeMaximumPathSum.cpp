// Last updated: 5/10/2026, 4:40:50 PM
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
15    int maxSum = INT_MIN;
16
17    int calculateMaxPath(TreeNode* root) {
18        if (!root)
19            return 0;
20        int left = max(0, calculateMaxPath(root->left));
21        int right = max(0, calculateMaxPath(root->right));
22        maxSum = max(maxSum, root->val + left + right);
23        return root->val + max(left, right);
24    }
25
26public:
27    int maxPathSum(TreeNode* root) {
28        calculateMaxPath(root);
29        return maxSum;
30    }
31};
32
// Last updated: 7/3/2026, 10:04:56 AM
1class Solution {
2public:
3    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
4        // 1. The Base Cases
5        // If we hit the bottom, return null.
6        // If we ARE one of the targets, immediately return ourselves!
7        if (!root || root == p || root == q) 
8            return root;
9
10        // 2. Send scouts down the left and right branches (Post-Order Traversal)
11        TreeNode* left = lowestCommonAncestor(root->left, p, q);
12        TreeNode* right = lowestCommonAncestor(root->right, p, q);
13
14        // 3. Post-Processing: Evaluate the reports
15
16        // THE WINNING CASE: Both departments found a target. We are the LCA!
17        if (left && right) 
18            return root;
19
20        // THE PASS-IT-UP CASE: If one side is null, return the side that ISN'T
21        // null. (If both are null, this conveniently just returns null anyway).
22        return left ? left : right;
23    }
24};
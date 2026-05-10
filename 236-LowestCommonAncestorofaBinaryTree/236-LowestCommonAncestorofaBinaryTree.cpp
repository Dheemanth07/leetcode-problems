// Last updated: 5/10/2026, 4:21:36 PM
1class Solution {
2public:
3    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
4        // 1. The Base Cases
5        // If we hit the bottom, return null.
6        // If we ARE one of the targets, immediately return ourselves!
7        if (root == nullptr || root == p || root == q) {
8            return root;
9        }
10
11        // 2. The Leap of Faith (Wait for the reports)
12        TreeNode* leftReport = lowestCommonAncestor(root->left, p, q);
13        TreeNode* rightReport = lowestCommonAncestor(root->right, p, q);
14
15        // 3. Post-Processing: Evaluate the reports
16
17        // THE WINNING CASE: Both departments found a target. We are the LCA!
18        if (leftReport != nullptr && rightReport != nullptr) {
19            return root;
20        }
21
22        // THE PASS-IT-UP CASE: If one side is null, return the side that ISN'T
23        // null. (If both are null, this conveniently just returns null anyway).
24        return leftReport != nullptr ? leftReport : rightReport;
25    }
26};
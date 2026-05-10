// Last updated: 5/10/2026, 4:26:45 PM
1class Solution {
2public:
3    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
4        TreeNode* curr = root;
5
6        while (curr) {
7            // 1. Both friends want to go Left
8            if (p->val < curr->val && q->val < curr->val) {
9                curr = curr->left;
10            }
11            // 2. Both friends want to go Right
12            else if (p->val > curr->val && q->val > curr->val) {
13                curr = curr->right;
14            }
15            // 3. The Fork in the Road!
16            // One is less, one is greater (or one is exactly equal to curr).
17            // We found the LCA!
18            else {
19                return curr;
20            }
21        }
22
23        return nullptr; // Safety net, though the problem guarantees an LCA
24                        // exists
25    }
26};
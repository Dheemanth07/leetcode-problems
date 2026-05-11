// Last updated: 5/11/2026, 10:40:21 AM
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
15    int rangeSumBST(TreeNode* root, int low, int high) {
16        // 1. Safety Net
17        if (root == nullptr) {
18            return 0;
19        }
20
21        int currentSum = 0;
22
23        // 2. The Goldilocks Case: We are in the sweet spot!
24        if (root->val >= low && root->val <= high) {
25            currentSum += root->val;
26            // Search BOTH sides, because valid numbers could be in either
27            // direction
28            currentSum += rangeSumBST(root->left, low, high);
29            currentSum += rangeSumBST(root->right, low, high);
30        }
31        // 3. The "Too Young" Case
32        else if (root->val < low) {
33            // Skip the left entirely! Only search right.
34            currentSum += rangeSumBST(root->right, low, high);
35        }
36        // 4. The "Too Old" Case
37        else if (root->val > high) {
38            // Skip the right entirely! Only search left.
39            currentSum += rangeSumBST(root->left, low, high);
40        }
41
42        return currentSum;
43    }
44};
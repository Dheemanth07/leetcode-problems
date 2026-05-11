// Last updated: 5/11/2026, 11:12:17 AM
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
15    bool isValidBST(TreeNode* root) {
16        // Kick off the DFS with the absolute widest possible boundaries
17        // LONG_MIN and LONG_MAX guarantee we don't overflow on INT edge cases.
18        return validate(root, LONG_MIN, LONG_MAX);
19    }
20
21private:
22    bool validate(TreeNode* node, long long minVal, long long maxVal) {
23        // 1. Safety Net: An empty tree is mathematically a valid BST
24        if (node == nullptr) {
25            return true;
26        }
27
28        // 2. The Boundary Check: Did this node step out of line?
29        // Note: BST strictly requires LESS THAN or GREATER THAN. Equal values
30        // are invalid!
31        if (node->val <= minVal || node->val >= maxVal) {
32            return false;
33        }
34
35        // 3. The Leap of Faith: Check both branches.
36        // If we go Left, our current value becomes the new strict MAXIMUM.
37        // If we go Right, our current value becomes the new strict MINIMUM.
38        return validate(node->left, minVal, node->val) &&
39               validate(node->right, node->val, maxVal);
40    }
41};
// Last updated: 5/10/2026, 5:58:44 PM
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
15    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
16        // 1. The Safety Net / Solo Node Checks
17        // If Tree 1 is missing a node here, just plug in Tree 2's node!
18        if (root1 == nullptr) {
19            return root2;
20        }
21        // If Tree 2 is missing a node here, just keep Tree 1's node!
22        if (root2 == nullptr) {
23            return root1;
24        }
25
26        // 2. The Overlap (Both nodes physically exist!)
27        // Since we are modifying Tree 1 in-place, we just add Tree 2's value to
28        // it.
29        root1->val += root2->val;
30
31        // 3. The Leap of Faith
32        // Tell the left hands to go merge the left subtrees,
33        // and the right hands to go merge the right subtrees.
34        root1->left = mergeTrees(root1->left, root2->left);
35        root1->right = mergeTrees(root1->right, root2->right);
36
37        // Return the fully merged Tree 1
38        return root1;
39    }
40};
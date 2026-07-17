// Last updated: 7/17/2026, 2:01:50 PM
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        // 1. Safety Net
        if (root == nullptr) {
            return 0;
        }

        int currentSum = 0;

        // 2. The Goldilocks Case: We are in the sweet spot!
        if (root->val >= low && root->val <= high) {
            currentSum += root->val;
            // Search BOTH sides, because valid numbers could be in either
            // direction
            currentSum += rangeSumBST(root->left, low, high);
            currentSum += rangeSumBST(root->right, low, high);
        }
        // 3. The "Too Young" Case
        else if (root->val < low) {
            // Skip the left entirely! Only search right.
            currentSum += rangeSumBST(root->right, low, high);
        }
        // 4. The "Too Old" Case
        else if (root->val > high) {
            // Skip the right entirely! Only search left.
            currentSum += rangeSumBST(root->left, low, high);
        }

        return currentSum;
    }
};
// Last updated: 6/22/2026, 6:30:34 PM
class Solution {
public:
    int sumRootToLeaf(TreeNode* root) {
        // Kick off the recursion with a starting sum of 0
        return dfs(root, 0);
    }

private:
    int dfs(TreeNode* node, int currentSum) {
        // 1. Safety Net
        if (!node) {
            return 0;
        }

        // 2. The Accumulation (Shift left by 1 and add the current bit)
        currentSum = (currentSum << 1) | node->val;
        // NOTE: currentSum = (currentSum * 2) + node->val; does the exact same
        // thing!

        // 3. The Leaf Check
        if (!node->left && !node->right) {
            // We reached the bottom! Return our fully built decimal number.
            return currentSum;
        }

        // 4. The Leap of Faith
        // We aren't returning true/false anymore. We are adding the results of
        // the left tree and the right tree together!
        return dfs(node->left, currentSum) + dfs(node->right, currentSum);
    }
};
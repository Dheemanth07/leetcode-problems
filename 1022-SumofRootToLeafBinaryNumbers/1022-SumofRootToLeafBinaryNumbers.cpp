// Last updated: 5/10/2026, 9:51:45 AM
1class Solution {
2public:
3    int sumRootToLeaf(TreeNode* root) {
4        // Kick off the recursion with a starting sum of 0
5        return dfs(root, 0);
6    }
7
8private:
9    int dfs(TreeNode* node, int currentSum) {
10        // 1. Safety Net
11        if (!node) {
12            return 0;
13        }
14
15        // 2. The Accumulation (Shift left by 1 and add the current bit)
16        currentSum = (currentSum << 1) | node->val;
17        // NOTE: currentSum = (currentSum * 2) + node->val; does the exact same
18        // thing!
19
20        // 3. The Leaf Check
21        if (!node->left && !node->right) {
22            // We reached the bottom! Return our fully built decimal number.
23            return currentSum;
24        }
25
26        // 4. The Leap of Faith
27        // We aren't returning true/false anymore. We are adding the results of
28        // the left tree and the right tree together!
29        return dfs(node->left, currentSum) + dfs(node->right, currentSum);
30    }
31};
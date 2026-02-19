// Last updated: 2/19/2026, 11:55:05 AM
1class Solution {
2public:
3    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
4        if (!root) return {};
5
6        vector<vector<int>> res;
7        queue<TreeNode*> q;
8        q.push(root);
9        bool leftToRight = true; // Toggle this every level
10
11        while (!q.empty()) {
12            int levelSize = q.size();
13            vector<int> currentLevel(levelSize);
14
15            for (int i = 0; i < levelSize; i++) {
16                TreeNode* node = q.front();
17                q.pop();
18
19                // Determine the position to fill in the vector
20                int index = leftToRight ? i : (levelSize - 1 - i);
21                currentLevel[index] = node->val;
22
23                if (node->left) q.push(node->left);
24                if (node->right) q.push(node->right);
25            }
26
27            res.push_back(currentLevel);
28            leftToRight = !leftToRight; // Flip direction for the next level
29        }
30        return res;
31    }
32};
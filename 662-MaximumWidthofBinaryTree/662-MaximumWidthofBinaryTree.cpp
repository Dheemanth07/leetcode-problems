// Last updated: 7/4/2026, 10:25:18 PM
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
15    int widthOfBinaryTree(TreeNode* root) {
16        if (!root)
17            return 0;
18
19        int maxWidth = 0;
20
21        queue<pair<TreeNode*, long long>> q;
22        q.push({root, 0});
23
24        while (!q.empty()) {
25            int levelStartIndex = q.front().second;
26
27            int firstIndex = 0, lastIndex = 0;
28
29            int levelSize = q.size();
30
31            for (int i = 0; i < levelSize; i++) {
32                TreeNode* cur = q.front().first;
33                long long rawIndex = q.front().second;
34                q.pop();
35
36                long long normalizedIndex = rawIndex - levelStartIndex;
37
38                if (!i)
39                    firstIndex = normalizedIndex;
40
41                lastIndex = normalizedIndex;
42
43                if (cur->left)
44                    q.push({cur->left, 2 * normalizedIndex});
45                if (cur->right)
46                    q.push({cur->right, 2 * normalizedIndex + 1});
47
48                int width = lastIndex - firstIndex + 1;
49                maxWidth = max(maxWidth, width);
50            }
51        }
52        return maxWidth;
53    }
54};
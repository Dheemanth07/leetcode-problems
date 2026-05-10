// Last updated: 5/10/2026, 5:07:43 PM
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
13
14class Solution {
15private:
16    // Our self-sorting database: map<Column, map<Row, multiset<Value>>>
17    map<int, map<int, multiset<int>>> database;
18
19    void dfs(TreeNode* node, int col, int row) {
20        if (!node)
21            return;
22
23        // 1. The Work: Insert the node's value into the correct (col, row)
24        // slot. The maps and multiset instantly, automatically sort it upon
25        // insertion!
26        database[col][row].insert(node->val);
27
28        // 2. The Leap of Faith: Traverse left and right, updating the
29        // coordinates
30        dfs(node->left, col - 1, row + 1);
31        dfs(node->right, col + 1, row + 1);
32    }
33
34public:
35    vector<vector<int>> verticalTraversal(TreeNode* root) {
36        // Kick off DFS with the root at (0, 0)
37        dfs(root, 0, 0);
38
39        vector<vector<int>> result;
40
41        // Unpack the self-sorted database into our final 2D array
42        // Iterate through columns (already sorted from leftmost to rightmost)
43        for (auto const& [col, rowsMap] : database) {
44            vector<int> currentColumn;
45
46            // Iterate through rows in this column (already sorted top to
47            // bottom)
48            for (auto const& [row, valuesSet] : rowsMap) {
49
50                // Iterate through the values at this exact (col, row)
51                // (already sorted smallest to largest!)
52                for (int val : valuesSet) {
53                    currentColumn.push_back(val);
54                }
55            }
56
57            result.push_back(currentColumn);
58        }
59
60        return result;
61    }
62};
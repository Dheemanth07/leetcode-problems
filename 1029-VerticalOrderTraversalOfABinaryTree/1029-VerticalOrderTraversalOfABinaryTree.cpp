// Last updated: 6/22/2026, 6:30:42 PM
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
private:
    // Our self-sorting database: map<Column, map<Row, multiset<Value>>>
    map<int, map<int, multiset<int>>> database;

    void dfs(TreeNode* node, int col, int row) {
        if (!node)
            return;

        // 1. The Work: Insert the node's value into the correct (col, row)
        // slot. The maps and multiset instantly, automatically sort it upon
        // insertion!
        database[col][row].insert(node->val);

        // 2. The Leap of Faith: Traverse left and right, updating the
        // coordinates
        dfs(node->left, col - 1, row + 1);
        dfs(node->right, col + 1, row + 1);
    }

public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // Kick off DFS with the root at (0, 0)
        dfs(root, 0, 0);

        vector<vector<int>> result;

        // Unpack the self-sorted database into our final 2D array
        // Iterate through columns (already sorted from leftmost to rightmost)
        for (auto const& [col, rowsMap] : database) {
            vector<int> currentColumn;

            // Iterate through rows in this column (already sorted top to
            // bottom)
            for (auto const& [row, valuesSet] : rowsMap) {

                // Iterate through the values at this exact (col, row)
                // (already sorted smallest to largest!)
                for (int val : valuesSet) {
                    currentColumn.push_back(val);
                }
            }

            result.push_back(currentColumn);
        }

        return result;
    }
};
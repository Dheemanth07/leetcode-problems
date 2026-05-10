// Last updated: 5/10/2026, 9:40:04 AM
1class Solution {
2public:
3    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
4        vector<vector<int>> result;
5        vector<int> currentPath;
6
7        // Kick off the recursion
8        dfs(root, targetSum, currentPath, result);
9
10        return result;
11    }
12
13private:
14    // Notice the '&' references! We are modifying the exact same arrays
15    // everywhere.
16    void dfs(TreeNode* node, int targetSum, vector<int>& currentPath,
17             vector<vector<int>>& result) {
18        if (node == nullptr)
19            return;
20
21        // 1. Reel the string out: Add the current node to our path
22        currentPath.push_back(node->val);
23
24        // 2. The Leaf Check
25        if (node->left == nullptr && node->right == nullptr &&
26            targetSum == node->val) {
27            // We found a winning path!
28            // Because currentPath is a vector, we can just copy the whole thing
29            // instantly!
30            result.push_back(currentPath);
31        } else {
32            // 3. The Leap of Faith: Keep going down
33            dfs(node->left, targetSum - node->val, currentPath, result);
34            dfs(node->right, targetSum - node->val, currentPath, result);
35        }
36
37        // 4. THE BACKTRACK: Reel the string back in!
38        // We are done with this node, so we remove it from the path before
39        // going back up to the parent.
40        currentPath.pop_back();
41    }
42};
// Last updated: 5/11/2026, 4:31:18 PM
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
16    // The Detective's global tracker
17    int preorderIndex = 0;
18    // The Map's instant-lookup directory
19    unordered_map<int, int> inorderMap;
20
21    TreeNode* build(vector<int>& preorder, int left, int right) {
22        // 1. Safety Net / Boundary Check
23        // If the left boundary crosses the right boundary, there are no nodes
24        // left to build!
25        if (left > right) {
26            return nullptr;
27        }
28
29        // 2. The Detective finds the Root
30        int rootVal = preorder[preorderIndex++];
31        TreeNode* root =
32            new TreeNode(rootVal); // Physically allocate the memory!
33
34        // 3. The Map splits the neighborhoods
35        int mid = inorderMap[rootVal];
36
37        // 4. The Leap of Faith (Build the children)
38        // Left child gets everything strictly to the left of 'mid'
39        root->left = build(preorder, left, mid - 1);
40        // Right child gets everything strictly to the right of 'mid'
41        root->right = build(preorder, mid + 1, right);
42
43        // Return the fully constructed branch
44        return root;
45    }
46
47public:
48    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
49        // Step 1: Pre-process the Map for instant O(1) lookups
50        for (int i = 0; i < inorder.size(); i++) {
51            inorderMap[inorder[i]] = i;
52        }
53
54        // Step 2: Kick off the recursion using the entire Map boundary
55        return build(preorder, 0, inorder.size() - 1);
56    }
57};
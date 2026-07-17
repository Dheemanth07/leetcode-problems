// Last updated: 7/17/2026, 2:01:51 PM
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
    unordered_map<int, int> postorderMap;
    int preIdx = 0;

    TreeNode* build(vector<int>& preorder, vector<int>& postorder, int left,
                    int right) {
        if (left > right)
            return nullptr;

        TreeNode* node = new TreeNode(preorder[preIdx++]);

        if (left == right)
            return node;

        int leftRootVal = preorder[preIdx];

        int mid = postorderMap[leftRootVal];
        node->left = build(preorder, postorder, left, mid);
        node->right = build(preorder, postorder, mid + 1, right - 1);

        return node;
    }

    TreeNode* constructFromPrePost(vector<int>& preorder,
                                   vector<int>& postorder) {

        for (int i = 0; i < postorder.size(); i++)
            postorderMap[postorder[i]] = i;

        return build(preorder, postorder, 0, postorder.size() - 1);
    }
};
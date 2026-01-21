// Last updated: 1/21/2026, 10:22:04 PM
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void allpaths(TreeNode*root, string path,vector<string>& ans){
         if(root==NULL) return;
          path+=to_string(root->val);
        if(root->left==NULL && root->right==NULL)
        {
            ans.push_back(path);
            return;
        }
        path+="->";
        allpaths(root->left, path, ans);
        allpaths(root->right, path, ans);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
       vector<string> ans;
        allpaths(root, "", ans);
        return ans;
        
    }
};
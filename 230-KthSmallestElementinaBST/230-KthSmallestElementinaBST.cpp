// Last updated: 1/16/2026, 10:27:10 PM
1/**
2 * Definition for a binary tree node.
3 * struct TreeNode {
4 *     int val;
5 *     TreeNode *left;
6 *     TreeNode *right;
7 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
8 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
9 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
10 * };
11 */
12
13class Solution {
14public:
15    int kthSmallest(TreeNode* root, int k) {
16        stack<TreeNode*>st;
17        TreeNode*cur=root;
18        while(cur||!st.empty()){
19            while(cur){
20                st.push(cur);
21                cur=cur->left;
22            }
23        cur=st.top();
24        st.pop();
25        k--;
26        if(k==0)
27            return cur->val;
28        cur=cur->right;
29        }
30    return -1;
31    }
32};
33
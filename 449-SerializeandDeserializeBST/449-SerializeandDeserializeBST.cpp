// Last updated: 5/11/2026, 5:21:59 PM
1/**
2 * Definition for a binary tree node.
3 * struct TreeNode {
4 *     int val;
5 *     TreeNode *left;
6 *     TreeNode *right;
7 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
8 * };
9 */
10class Codec {
11public:
12    // SERIALIZE: No "N" ghosts needed! Just pure numbers.
13    string serialize(TreeNode* root) {
14        if (root == nullptr)
15            return "";
16        return to_string(root->val) + "," + serialize(root->left) +
17               serialize(root->right);
18    }
19
20    TreeNode* deserialize(string data) {
21        if (data.empty())
22            return nullptr;
23        stringstream ss(data);
24        return buildBST(ss, LONG_MAX); // Start with infinite boundary
25    }
26
27private:
28    TreeNode* buildBST(stringstream& ss, long long upperBound) {
29        // Peek at the current position of the conveyor belt WITHOUT consuming
30        // the token
31        if (ss.eof())
32            return nullptr;
33
34        // We have to peek at the string to see if the number violates our
35        // boundary
36        streampos originalPos = ss.tellg();
37        string token;
38        getline(ss, token, ',');
39
40        if (token.empty())
41            return nullptr;
42        int val = stoi(token);
43
44        // THE MAGIC: Does this number belong here?
45        if (val > upperBound) {
46            // It violates the BST rule! This branch is dead.
47            // Put the token back on the conveyor belt for the parent to use.
48            ss.seekg(originalPos);
49            return nullptr;
50        }
51
52        // The number belongs here! Build it.
53        TreeNode* root = new TreeNode(val);
54
55        // Left child's new boundary is the current node's value!
56        root->left = buildBST(ss, root->val);
57
58        // Right child keeps the original boundary
59        root->right = buildBST(ss, upperBound);
60
61        return root;
62    }
63};
64
65// Your Codec object will be instantiated and called as such:
66// Codec* ser = new Codec();
67// Codec* deser = new Codec();
68// string tree = ser->serialize(root);
69// TreeNode* ans = deser->deserialize(tree);
70// return ans;
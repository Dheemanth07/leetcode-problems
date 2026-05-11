// Last updated: 5/11/2026, 5:14:41 PM
1/**
2 * Definition for a binary tree node.
3 * struct TreeNode {
4 *     int val;
5 *     TreeNode *left;
6 *     TreeNode *right;
7 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
8 * };
9 */
10
11class Codec {
12public:
13    // --- SERIALIZE: Tree to String ---
14    string serialize(TreeNode* root) {
15        if (root == nullptr)
16            return "N,";
17
18        // Preorder: Root, Left, Right
19        string result = to_string(root->val) + ",";
20        result += serialize(root->left);
21        result += serialize(root->right);
22
23        return result;
24    }
25
26    // --- DESERIALIZE: String to Tree ---
27    TreeNode* deserialize(string data) {
28        // Load the string into a stringstream (the conveyor belt)
29        stringstream ss(data);
30        return buildTree(ss);
31    }
32
33private:
34    // Notice we pass the stringstream by reference (&) so it constantly moves
35    // forward!
36    TreeNode* buildTree(stringstream& ss) {
37        string token;
38        // Grab the next item off the conveyor belt, stopping at the comma
39        getline(ss, token, ',');
40
41        if (token == "N") {
42            return nullptr; // We hit a ghost! Branch ends here.
43        }
44
45        // 1. Build the Root
46        TreeNode* root = new TreeNode(stoi(token));
47
48        // 2. The Leap of Faith (Preorder forces Left, then Right)
49        root->left = buildTree(ss);
50        root->right = buildTree(ss);
51
52        return root;
53    }
54};
55
56// Your Codec object will be instantiated and called as such:
57// Codec ser, deser;
58// TreeNode* ans = deser.deserialize(ser.serialize(root));
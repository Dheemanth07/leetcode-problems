// Last updated: 5/11/2026, 5:18:29 PM
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
19        return to_string(root->val) + "," + serialize(root->left) + serialize(root->right);
20    }
21
22    // --- DESERIALIZE: String to Tree ---
23    TreeNode* deserialize(string data) {
24        // Load the string into a stringstream (the conveyor belt)
25        stringstream ss(data);
26        return buildTree(ss);
27    }
28
29private:
30    // Notice we pass the stringstream by reference (&) so it constantly moves
31    // forward!
32    TreeNode* buildTree(stringstream& ss) {
33        string token;
34        // Grab the next item off the conveyor belt, stopping at the comma
35        getline(ss, token, ',');
36
37        if (token == "N") {
38            return nullptr; // We hit a ghost! Branch ends here.
39        }
40
41        // 1. Build the Root
42        TreeNode* root = new TreeNode(stoi(token));
43
44        // 2. The Leap of Faith (Preorder forces Left, then Right)
45        root->left = buildTree(ss);
46        root->right = buildTree(ss);
47
48        return root;
49    }
50};
51
52// Your Codec object will be instantiated and called as such:
53// Codec ser, deser;
54// TreeNode* ans = deser.deserialize(ser.serialize(root));
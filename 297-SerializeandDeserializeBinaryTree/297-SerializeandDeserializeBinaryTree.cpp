// Last updated: 2/20/2026, 9:19:49 PM
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
12    // Serialize
13    void serializeHelper(TreeNode* root, string& s) {
14        if (!root) {
15            s += "#,";
16            return;
17        }
18        s += to_string(root->val) + ",";
19        serializeHelper(root->left, s);
20        serializeHelper(root->right, s);
21    }
22
23    string serialize(TreeNode* root) {
24        string s;
25        serializeHelper(root, s);
26        return s;
27    }
28
29    // Deserialize
30    TreeNode* deserializeHelper(queue<string>& q) {
31        string val = q.front();
32        q.pop();
33
34        if (val == "#")
35            return nullptr;
36
37        TreeNode* node = new TreeNode(stoi(val));
38        node->left = deserializeHelper(q);
39        node->right = deserializeHelper(q);
40        return node;
41    }
42
43    TreeNode* deserialize(string data) {
44        string token;
45        stringstream ss(data);
46        queue<string> q;
47
48        while (getline(ss, token, ',')) {
49            q.push(token);
50        }
51
52        return deserializeHelper(q);
53    }
54};
55
56// Your Codec object will be instantiated and called as such:
57// Codec ser, deser;
58// TreeNode* ans = deser.deserialize(ser.serialize(root));
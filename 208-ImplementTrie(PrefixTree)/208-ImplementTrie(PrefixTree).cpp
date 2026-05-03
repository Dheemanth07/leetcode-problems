// Last updated: 5/3/2026, 3:05:27 PM
1struct TrieNode {
2    TrieNode* children[26];
3    bool isWordEnd;
4
5    TrieNode() {
6        isWordEnd = false;
7
8        for (int i = 0; i < 26; i++)
9            children[i] = nullptr;
10    }
11};
12
13class Trie {
14    TrieNode* root;
15
16public:
17    Trie() { root = new TrieNode(); }
18
19    void insert(string word) {
20        TrieNode* cur = root;
21
22        for (char c : word) {
23            if (!cur->children[c - 'a']) {
24                TrieNode* newNode = new TrieNode();
25                cur->children[c - 'a'] = newNode;
26            }
27            cur = cur->children[c - 'a'];
28        }
29        cur->isWordEnd = true;
30    }
31
32    bool search(string word) {
33        TrieNode* cur = root;
34
35        for (char c : word) {
36            if (!cur->children[c - 'a'])
37                return false;
38            cur = cur->children[c - 'a'];
39        }
40        return cur->isWordEnd;
41    }
42
43    bool startsWith(string prefix) {
44        TrieNode* cur = root;
45
46        for (char c : prefix) {
47            if (!cur->children[c - 'a'])
48                return false;
49            cur = cur->children[c - 'a'];
50        }
51        return true;
52    }
53};
54
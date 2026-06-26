// Last updated: 6/26/2026, 12:52:29 PM
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
23            if (!cur->children[c - 'a']) 
24                cur->children[c - 'a'] = new TrieNode();
25
26            cur = cur->children[c - 'a'];
27        }
28        cur->isWordEnd = true;
29    }
30
31    bool search(string word) {
32        TrieNode* cur = root;
33
34        for (char c : word) {
35            if (!cur->children[c - 'a'])
36                return false;
37            cur = cur->children[c - 'a'];
38        }
39        return cur->isWordEnd;
40    }
41
42    bool startsWith(string prefix) {
43        TrieNode* cur = root;
44
45        for (char c : prefix) {
46            if (!cur->children[c - 'a'])
47                return false;
48            cur = cur->children[c - 'a'];
49        }
50        return true;
51    }
52};
53
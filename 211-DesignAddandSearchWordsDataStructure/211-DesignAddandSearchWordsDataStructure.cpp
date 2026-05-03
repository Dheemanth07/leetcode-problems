// Last updated: 5/3/2026, 3:13:19 PM
1struct TrieNode {
2    TrieNode* children[26];
3    bool is_end_of_word;
4
5    TrieNode() {
6        is_end_of_word = false;
7        for (int i = 0; i < 26; i++) {
8            children[i] = nullptr;
9        }
10    }
11};
12
13class WordDictionary {
14private:
15    TrieNode* root;
16
17    // We need a helper function to keep track of what index of the word we are
18    // on
19    bool searchHelper(std::string& word, int index, TrieNode* node) {
20
21        for (int i = index; i < word.length(); i++) {
22            char c = word[i];
23
24            // ==========================================
25            // SCENARIO 1: We hit a wildcard!
26            // ==========================================
27            if (c == '.') {
28                // We must check every possible existing child path
29                for (int j = 0; j < 26; j++) {
30                    if (node->children[j] != nullptr) {
31                        // Recursively search the rest of the word starting from
32                        // this child. Notice we pass 'i + 1' to move to the
33                        // next letter in the word!
34                        if (searchHelper(word, i + 1, node->children[j])) {
35                            return true; // We found a valid path!
36                        }
37                    }
38                }
39                // If we checked all 26 paths and none of them returned true,
40                // it's a dead end.
41                return false;
42            }
43            // ==========================================
44            // SCENARIO 2: It's a normal letter
45            // ==========================================
46            else {
47                int char_idx = c - 'a';
48                if (node->children[char_idx] == nullptr) {
49                    return false; // Path doesn't exist
50                }
51                // Step down to the next node
52                node = node->children[char_idx];
53            }
54        }
55
56        // We reached the end of the word. Is this a valid inserted word?
57        return node->is_end_of_word;
58    }
59
60public:
61    WordDictionary() { root = new TrieNode(); }
62
63    void addWord(std::string word) {
64        TrieNode* current = root;
65        for (char c : word) {
66            int index = c - 'a';
67            if (current->children[index] == nullptr) {
68                current->children[index] = new TrieNode();
69            }
70            current = current->children[index];
71        }
72        current->is_end_of_word = true;
73    }
74
75    bool search(std::string word) {
76        // Start the recursive search from the root, at index 0 of the word
77        return searchHelper(word, 0, root);
78    }
79};
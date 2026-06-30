// Last updated: 6/30/2026, 10:43:46 PM
1/*
2// Definition for a Node.
3class Node {
4public:
5    int val;
6    Node* next;
7    Node* random;
8
9    Node(int _val) {
10        val = _val;
11        next = NULL;
12        random = NULL;
13    }
14};
15*/
16
17class Solution {
18public:
19    Node* copyRandomList(Node* head) {
20        // Base case: If the original list is completely empty,
21        // there is nothing to copy.
22        if (!head)
23            return nullptr;
24
25        // The Hash Map acts as our "Ledger".
26        // Key: Memory address of the Original Node
27        // Value: Memory address of the corresponding Clone Node
28        unordered_map<Node*, Node*> mp;
29
30        Node* cur = head;
31
32        // --- PASS 1: Build the Boxes (Clones) ---
33        // Walk down the original list and create a brand new node for every
34        // existing node. We only copy the value right now; pointers remain
35        // NULL.
36        while (cur) {
37            mp[cur] = new Node(cur->val);
38            cur = cur->next;
39        }
40
41        // Reset our traversal pointer back to the start of the original list
42        // so we can walk through it a second time.
43        cur = head;
44
45        // --- PASS 2: Wire up the Pointers ---
46        // Now that every clone exists in memory, we can safely set their
47        // pointers without worrying about pointing to something that hasn't
48        // been built yet.
49        while (cur) {
50            // mp[cur] gives us the Clone of the current node.
51
52            // Look at where the Original node's 'next' points, find THAT clone
53            // in the ledger, and wire it up.
54            // (If cur->next is NULL, the map safely returns nullptr).
55            mp[cur]->next = mp[cur->next];
56
57            // Look at where the Original node's 'random' points, find THAT
58            // clone in the ledger, and wire it up.
59            mp[cur]->random = mp[cur->random];
60
61            // Move to the next node in the original list
62            cur = cur->next;
63        }
64
65        // Return the clone of the original head node, which is the
66        // starting point of our fully wired, deeply copied new list.
67        return mp[head];
68    }
69};
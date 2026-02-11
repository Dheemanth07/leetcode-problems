// Last updated: 2/11/2026, 7:39:33 PM
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
20        if (!head)
21            return NULL;
22
23        Node* curr = head;
24
25        // Step 1: Insert copy nodes
26        while (curr) {
27            Node* newNode = new Node(curr->val);
28            newNode->next = curr->next;
29            curr->next = newNode;
30            curr = newNode->next;
31        }
32
33        // Step 2: Assign random pointers
34        curr = head;
35        while (curr) {
36            if (curr->random) {
37                curr->next->random = curr->random->next;
38            }
39            curr = curr->next->next;
40        }
41
42        // Step 3: Separate the lists
43        curr = head;
44        Node* newHead = head->next;
45        Node* copy = newHead;
46
47        while (curr) {
48            curr->next = curr->next->next;
49            if (copy->next) {
50                copy->next = copy->next->next;
51            }
52            curr = curr->next;
53            copy = copy->next;
54        }
55
56        return newHead;
57    }
58};
// Last updated: 7/1/2026, 10:56:34 AM
1class Node {
2public:
3    int key;
4    int val;
5    Node* next;
6    Node* prev;
7
8    Node(int key, int val) {
9        this->key = key;
10        this->val = val;
11        next = nullptr;
12        prev = nullptr;
13    }
14};
15
16class LRUCache {
17private:
18    int capacity;
19    unordered_map<int, Node*> map; // Maps Key -> Memory Address of Node
20
21    // Dummy nodes to make insertion/deletion seamless
22    Node* head;
23    Node* tail;
24
25    void addNode(Node* newNode) {
26        Node* temp = head->next; // The current first real node
27
28        // Squeeze newNode between dummy head and temp
29        newNode->next = temp;
30        newNode->prev = head;
31
32        head->next = newNode;
33        temp->prev = newNode;
34    }
35
36    void deleteNode(Node* delNode) {
37        Node* prevNode = delNode->prev;
38        Node* nextNode = delNode->next;
39
40        // Unplug delNode by connecting its neighbors directly to each other
41        prevNode->next = nextNode;
42        nextNode->prev = prevNode;
43    }
44
45public:
46    LRUCache(int capacity) {
47        this->capacity = capacity;
48        head = new Node(-1, -1);
49        tail = new Node(-1, -1);
50
51        // Connect the dummy head and tail together
52        head->next = tail;
53        tail->prev = head;
54    }
55
56    int get(int key) {
57        // If the key doesn't exist, return -1
58        if (map.find(key) == map.end()) {
59            return -1;
60        }
61
62        // If it DOES exist, get the node
63        Node* resNode = map[key];
64        int res = resNode->val;
65
66        // Move it to the Most Recently Used position (right after head)
67        deleteNode(resNode);
68        addNode(resNode);
69
70        return res;
71    }
72
73    void put(int key, int value) {
74        // If the key already exists, we must update it
75        if (map.find(key) != map.end()) {
76            Node* existingNode = map[key];
77            map.erase(key);           // Remove old reference
78            deleteNode(existingNode); // Unplug old node
79            delete existingNode;      // Free memory
80        }
81
82        // If we are at capacity, we must delete the Least Recently Used item
83        if (map.size() == capacity) {
84            Node* lruNode = tail->prev; // The node right before the dummy tail
85            map.erase(lruNode->key);    // Delete it from the Hash Map
86            deleteNode(lruNode);        // Unplug it from the list
87            delete lruNode;             // Free memory
88        }
89
90        // Create the new node, add it right after head, and log it in the Hash
91        // Map
92        Node* newNode = new Node(key, value);
93        addNode(newNode);
94        map[key] = newNode;
95    }
96};
97
// Last updated: 2/26/2026, 8:37:40 PM
1/*
2// Definition for a Node.
3class Node {
4public:
5    int val;
6    vector<Node*> neighbors;
7    Node() {
8        val = 0;
9        neighbors = vector<Node*>();
10    }
11    Node(int _val) {
12        val = _val;
13        neighbors = vector<Node*>();
14    }
15    Node(int _val, vector<Node*> _neighbors) {
16        val = _val;
17        neighbors = _neighbors;
18    }
19};
20*/
21
22class Solution {
23public:
24    unordered_map<Node*, Node*> visited;
25    Node* cloneGraph(Node* node) {
26        if (!node)
27            return NULL;
28
29        if (visited.find(node) != visited.end())
30            return visited[node];
31
32        Node* clone = new Node(node->val);
33        visited[node] = clone;
34
35        for (Node* neighbor : node->neighbors)
36            clone->neighbors.push_back(cloneGraph(neighbor));
37
38        return clone;
39    }
40};
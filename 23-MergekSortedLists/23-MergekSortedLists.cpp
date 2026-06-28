// Last updated: 6/28/2026, 5:11:06 PM
1/**
2 * Definition for singly-linked list.
3 * struct ListNode {
4 *     int val;
5 *     ListNode *next;
6 *     ListNode() : val(0), next(nullptr) {}
7 *     ListNode(int x) : val(x), next(nullptr) {}
8 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
9 * };
10 */
11
12class Solution {
13public:
14    ListNode* mergeKLists(vector<ListNode*>& lists) {
15
16        auto cmp = [](ListNode* a, ListNode* b) { return a->val > b->val; };
17
18        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);
19
20        for (auto list : lists)
21            if (list)
22                pq.push(list);
23
24        ListNode dummy(0);
25        ListNode* cur = &dummy;
26
27        while (!pq.empty()) {
28            ListNode* node = pq.top();
29            pq.pop();
30            cur->next = node;
31            cur = cur->next;
32            if (node->next)
33                pq.push(node->next);
34        }
35
36        return dummy.next;
37    }
38};
39
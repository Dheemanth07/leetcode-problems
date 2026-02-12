// Last updated: 2/12/2026, 6:43:16 PM
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
15        auto cmp = [](ListNode* a, ListNode* b) { return a->val > b->val; };
16        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);
17        for (auto list : lists)
18            if (list)
19                pq.push(list);
20        ListNode dummy(0);
21        ListNode* cur = &dummy;
22        while (!pq.empty()) {
23            ListNode* node = pq.top();
24            pq.pop();
25            cur->next = node;
26            cur = cur->next;
27            if (node->next)
28                pq.push(node->next);
29        }
30        return dummy.next;
31    }
32};
33
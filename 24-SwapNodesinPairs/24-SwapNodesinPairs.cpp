// Last updated: 7/1/2026, 12:55:38 PM
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
11class Solution {
12public:
13    ListNode* swapPairs(ListNode* head) {
14        if (!head || !head->next)
15            return head;
16
17        ListNode* cur = head;
18        ListNode* prev = nullptr;
19        for (int i = 0; i < 2; i++) {
20            ListNode* temp = cur->next;
21            cur->next = prev;
22            prev = cur;
23            cur = temp;
24        }
25
26        if (cur)
27            head->next = swapPairs(cur);
28
29        return prev;
30    }
31};
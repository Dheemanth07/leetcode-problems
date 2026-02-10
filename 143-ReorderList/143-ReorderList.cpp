// Last updated: 2/10/2026, 7:11:10 PM
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
13    void reorderList(ListNode* head) {
14        if (!head || !head->next)
15            return;
16        ListNode *slow = head, *fast = head->next;
17        while (fast && fast->next) {
18            fast = fast->next->next;
19            slow = slow->next;
20        }
21        ListNode *prev = nullptr, *cur = slow->next;
22        while (cur) {
23            ListNode* temp = cur->next;
24            cur->next = prev;
25            prev = cur;
26            cur = temp;
27        }
28        slow->next = nullptr;
29        ListNode *first = head, *second = prev;
30        ListNode* newHead = first;
31        while (second) {
32            ListNode* temp1 = first->next;
33            ListNode* temp2 = second->next;
34            first->next = second;
35            second->next = temp1;
36            first = temp1;
37            second = temp2;
38        }
39    }
40};
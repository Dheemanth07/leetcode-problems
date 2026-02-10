// Last updated: 2/10/2026, 7:11:53 PM
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
13    ListNode* removeNthFromEnd(ListNode* head, int n) {
14        ListNode dummy(0);
15        dummy.next = head;
16        ListNode* slow = &dummy;
17        ListNode* fast = &dummy;
18        for (int i = 0; i <= n; i++)
19            fast = fast->next;
20        while (fast) {
21            slow = slow->next;
22            fast = fast->next;
23        }
24        slow->next = slow->next->next;
25        return dummy.next;
26    }
27};
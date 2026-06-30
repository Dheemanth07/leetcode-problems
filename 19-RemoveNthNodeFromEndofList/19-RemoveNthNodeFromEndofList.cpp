// Last updated: 6/30/2026, 10:25:42 PM
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
16
17        ListNode* slow = &dummy;
18        ListNode* fast = &dummy;
19
20        for (int i = 0; i <= n; i++)
21            fast = fast->next;
22
23        while (fast) {
24            slow = slow->next;
25            fast = fast->next;
26        }
27        
28        slow->next = slow->next->next;
29        return dummy.next;
30    }
31};
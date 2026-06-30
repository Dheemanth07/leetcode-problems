// Last updated: 6/30/2026, 8:59:41 PM
1/**
2 * Definition for singly-linked list.
3 * struct ListNode {
4 *     int val;
5 *     ListNode *next;
6 *     ListNode(int x) : val(x), next(NULL) {}
7 * };
8 */
9class Solution {
10public:
11    bool hasCycle(ListNode* head) {
12        if (!head)
13            return false;
14        ListNode *slow = head, *fast = head;
15
16        while (fast && fast->next) {
17            slow = slow->next;
18            fast = fast->next->next;
19
20            if (slow == fast)
21                return true;
22        }
23
24        return false;
25    }
26};
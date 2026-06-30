// Last updated: 6/30/2026, 9:03:03 PM
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
11    ListNode* detectCycle(ListNode* head) {
12        if (!head || !head->next)
13            return nullptr;
14
15        ListNode *slow = head, *fast = head;
16
17        while (fast && fast->next) {
18            slow = slow->next;
19            fast = fast->next->next;
20
21            if (slow == fast) {
22                fast = head;
23
24                while (slow != fast) {
25                    slow = slow->next;
26                    fast = fast->next;
27                }
28
29                return slow;
30            }
31        }
32
33        return nullptr;
34    }
35};
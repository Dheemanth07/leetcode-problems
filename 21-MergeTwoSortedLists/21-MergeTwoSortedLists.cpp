// Last updated: 6/30/2026, 6:43:20 PM
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
14    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
15
16        ListNode dummy(0);
17        ListNode* tail = &dummy;
18
19        while (list1 && list2) {
20
21            if (list1->val < list2->val) {
22                tail->next = list1;
23                list1 = list1->next;
24            } else {
25                tail->next = list2;
26                list2 = list2->next;
27            }
28
29            tail = tail->next;
30        }
31
32        tail->next = list1 ? list1 : list2;
33
34        return dummy.next;
35    }
36};
37
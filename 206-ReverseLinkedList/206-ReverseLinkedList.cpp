// Last updated: 2/9/2026, 9:31:19 PM
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
13    ListNode* reverseList(ListNode* head) {
14        ListNode* prev = nullptr;
15        ListNode* cur = head;
16        while (cur) {
17            ListNode* temp = cur->next;
18            cur->next = prev;
19            prev = cur;
20            cur = temp;
21        }
22        return prev;
23    }
24};
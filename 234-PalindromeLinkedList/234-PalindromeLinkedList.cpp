// Last updated: 5/8/2026, 11:39:13 AM
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
13    bool isPalindrome(ListNode* head) {
14        if (!head || !head->next)
15            return true;
16
17        ListNode* slow = head;
18        ListNode* fast = head;
19
20        while (fast && fast->next) {
21            slow = slow->next;
22            fast = fast->next->next;
23        }
24
25        ListNode* prev = nullptr;
26        ListNode* cur = slow;
27
28        while (cur) {
29            ListNode* temp = cur->next;
30            cur->next = prev;
31            prev = cur;
32            cur = temp;
33        }
34
35        ListNode* left = head;
36        ListNode* right = prev;
37
38        while (right) {
39            if (left->val != right->val)
40                return false;
41            left = left->next;
42            right = right->next;
43        }
44        return true;
45    }
46};
// Last updated: 2/12/2026, 9:07:22 PM
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
14    ListNode* reverseKGroup(ListNode* head, int k) {
15        ListNode* dummy = new ListNode(0);
16        dummy->next = head;
17        ListNode* prevGroup = dummy;
18
19        while (true) {
20            ListNode* kth = prevGroup;
21
22            for (int i = 0; i < k && kth != nullptr; i++)
23                kth = kth->next;
24
25            if (kth == nullptr)
26                break;
27
28            ListNode* groupStart = prevGroup->next;
29            ListNode* nextGroup = kth->next;
30
31            ListNode* cur = groupStart;
32            ListNode* prev = nextGroup;
33
34            while (cur != nextGroup) {
35                ListNode* temp = cur->next;
36                cur->next = prev;
37                prev = cur;
38                cur = temp;
39            }
40            prevGroup->next = kth;
41            prevGroup = groupStart;
42        }
43        return dummy->next;
44    }
45};
46
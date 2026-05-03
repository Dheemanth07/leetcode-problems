// Last updated: 5/3/2026, 9:49:04 AM
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
14        if (!head || !head->next || !head->next->next)
15            return;
16
17        // ==========================================
18        // PHASE 1: Find the middle using Fast & Slow
19        // ==========================================
20        ListNode* slow = head;
21        ListNode* fast = head;
22
23        while (fast && fast->next) {
24            slow = slow->next;
25            fast = fast->next->next;
26        }
27
28        // Split the list into two halves
29        ListNode* second_half = slow->next;
30        slow->next = nullptr; // Sever the connection!
31
32        // ==========================================
33        // PHASE 2: Reverse the second half
34        // ==========================================
35        ListNode* prev = nullptr;
36        ListNode* curr = second_half;
37
38        while (curr) {
39            ListNode* next_temp = curr->next;
40            curr->next = prev;
41            prev = curr;
42            curr = next_temp;
43        }
44
45        // 'prev' is now the head of the reversed second half
46        second_half = prev;
47        ListNode* first_half = head;
48
49        // ==========================================
50        // PHASE 3: Zip Merge the two halves
51        // ==========================================
52        while (second_half) {
53            // Save the next nodes before we overwrite the pointers
54            ListNode* temp1 = first_half->next;
55            ListNode* temp2 = second_half->next;
56
57            // Zip them together
58            first_half->next = second_half;
59            second_half->next = temp1;
60
61            // Move pointers forward for the next iteration
62            first_half = temp1;
63            second_half = temp2;
64        }
65    }
66};
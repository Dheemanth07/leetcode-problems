// Last updated: 7/1/2026, 12:58:53 PM
1class Solution {
2public:
3    ListNode* swapPairs(ListNode* head) {
4        // Create a dummy node to act as our initial 'prev'
5        ListNode dummy(0);
6        dummy.next = head;
7        ListNode* prev = &dummy;
8
9        // We can only swap if there are at least two nodes left ahead of us
10        while (prev->next && prev->next->next) {
11
12            // Identify the two nodes to swap
13            ListNode* first = prev->next;
14            ListNode* second = prev->next->next;
15
16            // The 3-Step Rewiring
17            prev->next = second;        // Step 1
18            first->next = second->next; // Step 2
19            second->next = first;       // Step 3
20
21            // Move prev forward by 2 steps to prepare for the next pair
22            prev = first;
23        }
24
25        // Return the new head of the list
26        return dummy.next;
27    }
28};
// Last updated: 6/30/2026, 6:38:54 PM
1class Solution {
2public:
3    ListNode* reverseBetween(ListNode* head, int left, int right) {
4        if (!head || left == right)
5            return head;
6
7        // 1. Create a dummy node to handle the left == 1 edge case safely
8        ListNode dummy(0);
9        dummy.next = head;
10        ListNode* before = &dummy;
11
12        // 2. Move 'before' just outside the reversal zone.
13        // We use a for-loop so we don't destroy the 'left' variable.
14        for (int i = 1; i < left; i++) 
15            before = before->next;
16
17        // 3. Set up our reversal pointers
18        ListNode* cur = before->next;
19        ListNode* subListTail = cur; // This will become the tail after reversal
20        ListNode* prev = nullptr;
21
22        // 4. Standard Reversal Loop (using your exact logic!)
23        for (int i = 0; i < right - left + 1; i++) {
24            ListNode* temp = cur->next;
25            cur->next = prev;
26            prev = cur;
27            cur = temp;
28        }
29
30        // 5. Re-link the reversed section back into the main list
31        before->next = prev; // Connect the left side to the new sublist head
32        subListTail->next = cur; // Connect the new sublist tail to the right side
33
34        // 6. Return the actual head
35        return dummy.next;
36    }
37};
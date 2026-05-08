// Last updated: 5/8/2026, 12:00:37 PM
1class Solution {
2public:
3    ListNode* removeElements(ListNode* head, int val) {
4        // 1. Create the Dummy Node on the stack (No memory leaks!)
5        ListNode dummy(0);
6        dummy.next = head;
7
8        // 2. Set up our standard two pointers
9        ListNode* prev = &dummy; // Prev starts ONE STEP BEHIND the head
10        ListNode* cur = head;    // Cur starts AT the head
11
12        while (cur != nullptr) {
13            if (cur->val == val) {
14                // We found a target!
15                // Just rewire prev to skip right over 'cur'
16                prev->next = cur->next;
17
18                // (Optional but good practice: you could technically 'delete
19                // cur' here in a real C++ environment to prevent memory leaks,
20                // but LeetCode doesn't require it).
21            } else {
22                // If it's not the target, just move prev forward normally
23                prev = cur;
24            }
25
26            // Cur ALWAYS moves forward, whether we deleted something or not
27            cur = cur->next;
28        }
29
30        // Return the true start of the list
31        return dummy.next;
32    }
33};
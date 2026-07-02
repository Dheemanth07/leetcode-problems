// Last updated: 7/2/2026, 6:33:15 PM
1class Solution {
2public:
3    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
4        // If either list is empty, an intersection is impossible
5        if (!headA || !headB)
6            return nullptr;
7
8        ListNode* ptrA = headA;
9        ListNode* ptrB = headB;
10
11        // Loop until the two pointers physically collide
12        while (ptrA != ptrB) {
13            // If ptrA hits the end, teleport to headB. Otherwise, step forward.
14            ptrA = (!ptrA) ? headB : ptrA->next;
15
16            // If ptrB hits the end, teleport to headA. Otherwise, step forward.
17            ptrB = (!ptrB) ? headA : ptrB->next;
18        }
19
20        // When the loop breaks, ptrA and ptrB are pointing to the exact same
21        // node! (Or they are both nullptr if the lists never intersected).
22        return ptrA;
23    }
24};
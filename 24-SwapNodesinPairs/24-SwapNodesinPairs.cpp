// Last updated: 7/1/2026, 1:00:14 PM
1class Solution {
2public:
3    ListNode* swapPairs(ListNode* head) {
4        // Base case: If there are 0 or 1 nodes left, we can't swap.
5        if (!head || !head->next) {
6            return head;
7        }
8
9        // 1. Identify the two nodes we are swapping
10        ListNode* firstNode = head;
11        ListNode* secondNode = head->next;
12
13        // 2. The recursive leap of faith!
14        // The first node connects to the fully swapped remainder of the list.
15        firstNode->next = swapPairs(secondNode->next);
16
17        // 3. The actual swap
18        // The second node turns around and points to the first node.
19        secondNode->next = firstNode;
20
21        // 4. Return the new head of this pair
22        return secondNode;
23    }
24};
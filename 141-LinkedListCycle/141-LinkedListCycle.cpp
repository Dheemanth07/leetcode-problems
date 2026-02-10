// Last updated: 2/10/2026, 7:10:25 PM
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head || !head->next) return false;

        ListNode* slow = head;
        ListNode* fast = slow->next;

        while (slow && fast) {
            if (slow == fast)
                return true;

            if (slow)
                slow = slow->next;
            
            if (fast->next)
                fast = fast->next->next;
            else 
                fast = nullptr;
        }

        return false;
    }
};
// Last updated: 7/2/2026, 6:30:27 PM
// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */
// class Solution {
// public:
//     bool checkPallindrome(vector<int> arr){
//         int n=arr.size();
//         int s=0;
//         int e=n-1;
        
//         while(s<=e){
//             if(arr[s]!=arr[e]){
//                 return 0;
//             }
//             s++;e--;
//         }
//         return 1;
//     }

//     bool isPalindrome(ListNode* head) {
//         vector<int> arr;
//         ListNode* temp=head;
//         while(temp!=NULL){
//             arr.push_back(temp->val);
//             temp=temp->next;
//         }
//         return checkPallindrome(arr);
//     }
// };




class Solution {
public:
    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* forward = NULL;

        while (curr != NULL) {
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return true;

        // Find the middle
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse second half
        slow->next = reverse(slow->next);

        // Compare both halves
        ListNode* first = head;
        ListNode* second = slow->next;

        while (second != NULL) {
            if (first->val != second->val)
                return false;

            first = first->next;
            second = second->next;
        }
        return true;
    }
};
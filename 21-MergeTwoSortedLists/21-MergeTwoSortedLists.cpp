// Last updated: 2/10/2026, 7:07:05 PM
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
13    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
14        ListNode dummy(0);
15        ListNode* list3=&dummy;
16        while(list1 && list2){
17            if(list1->val < list2->val){
18                list3->next=list1;
19                list1=list1->next;
20            }
21            else{
22                list3->next=list2;
23                list2=list2->next;
24            }
25            list3=list3->next;
26        }
27        list3->next = list1 ? list1 : list2;
28        return dummy.next;
29
30    }
31};
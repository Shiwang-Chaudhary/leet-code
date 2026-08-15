/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Better Solution
        // TC: O(n + m)
        // Auxiliary SC: O(1)
        // Output Space: O(n + m)
        // if(list1 == nullptr) return list2;
        // if(list2 == nullptr) return list1;
        // ListNode* temp1 = list1;
        // ListNode* temp2 = list2;
        // ListNode* dummy = new ListNode(-1);
        // ListNode* curr = dummy;
        // while(temp1 != nullptr && temp2 != nullptr){
        //     if(temp1->val < temp2->val){
        //         curr->next = new ListNode(temp1->val);
        //         curr = curr->next;
        //         temp1 = temp1->next;
        //     }else{
        //         curr->next = new ListNode(temp2->val);
        //         curr = curr->next;
        //         temp2 = temp2->next;
        //     }
        // }
        // while(temp1 != nullptr){
        //     curr->next = new ListNode(temp1->val);
        //     curr = curr->next;
        //     temp1 = temp1->next;
        // }
        // while(temp2 != nullptr){
        //     curr->next = new ListNode(temp2->val);
        //     curr = curr->next;
        //     temp2 = temp2->next;
        // }
        // return dummy->next;
        
        // Optimal Solution (In-place)
        // TC: O(n + m)
        // Auxiliary SC: O(1)
        // Output Space: O(0)
        // Total Space: O(1)
        if(list1 == nullptr) return list2;
        if(list2 == nullptr) return list1;
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;
        while(temp1 != nullptr && temp2 != nullptr){
            if(temp1->val < temp2->val){
                curr->next = temp1;
                curr = curr->next;
                temp1 = temp1->next;
            }else{
                curr->next = temp2;
                curr = curr->next;
                temp2 = temp2->next;
            }
        }
        while(temp1 != nullptr){
            curr->next = temp1;
            curr = curr->next;
            temp1 = temp1->next;
        }
        while(temp2 != nullptr){
            curr->next = temp2;
            curr = curr->next;
            temp2 = temp2->next;
        }
        return dummy->next;
    }
};
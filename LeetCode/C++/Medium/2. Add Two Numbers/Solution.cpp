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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //Not dummy node approach:
        //Optimal solution: But messier, TC: O(n) and SC: O(1)
        //Since constraints said l1 and l2 cant be null...
        // ListNode* temp1 = l1;
        // ListNode* temp2 = l2;
        // int carry = 0;
        // ListNode* head = nullptr;
        // ListNode* mover = nullptr;
        // while(temp1 != nullptr && temp2 != nullptr){
        //     int data1 = temp1->val;
        //     int data2 = temp2->val;
        //     int sum = data1 + data2 + carry;
        //     int digit = sum % 10;
        //     carry = sum / 10;
        //     ListNode* temp = new ListNode(digit);
        //     if(head == nullptr){
        //         head = temp;
        //         mover = head;
        //     }else{
        //         mover->next = temp;
        //         mover = mover->next;
        //     }
        //     temp1 = temp1->next;
        //     temp2 = temp2->next;
        // }
        // while(temp1 != nullptr){
        //     int data = temp1->val;
        //     int sum = data + carry;
        //     int digit = sum % 10;
        //     carry = sum / 10;
        //     ListNode* temp = new ListNode(digit);
        //     mover->next = temp;
        //     mover = mover->next;
        //     temp1 = temp1->next;
        // }
        // while(temp2 != nullptr){
        //     int data = temp2->val;
        //     int sum = data + carry;
        //     int digit = sum % 10;
        //     carry = sum / 10;
        //     ListNode* temp = new ListNode(digit);
        //     mover->next = temp;
        //     mover = mover->next;
        //     temp2 = temp2->next;
        // }
        // if(carry == 1){
        //     mover->next = new ListNode(carry);
        // }
        // return head;

        //Optimal solution (dummy node approach): TC: O(n) and SC: O(1)
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        int carry = 0;
        while(temp1 != nullptr || temp2 != nullptr){
            int sum = carry;
            if(temp1 != nullptr) sum = sum + temp1->val;
            if(temp2 != nullptr) sum = sum + temp2->val;
            int digit = sum % 10;
            carry = sum / 10;
            ListNode* newNode = new ListNode(digit);
            curr->next = newNode;
            curr = curr->next;
            if(temp1 != nullptr) temp1 = temp1->next;
            if(temp2 != nullptr) temp2 = temp2->next;
        }
        //We dont need to check for remaining because above while loop condition uses || instead of &&.....
        if(carry){
            ListNode* newNode = new ListNode(carry);
            curr->next = newNode;
            curr = curr->next;
        }
        //Because dummy node points to head of new LL
        return dummy->next;
    }
};
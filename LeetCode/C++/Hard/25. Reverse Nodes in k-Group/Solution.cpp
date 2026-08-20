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

    pair<ListNode*,ListNode*> reverseLL(ListNode* head){
        //Optimal solution: TC: O(n) and SC: O(1)
        ListNode* curr = head;       
        ListNode* front = nullptr;
        ListNode* back = nullptr;
        while(curr != nullptr){
            front = curr->next;
            curr->next = back;
            back = curr;
            curr = front;
        }
        ListNode* newHead = back;
        ListNode* newTail = head;
        //instead of last node, we will be sending first node:
        // LL: 1,2,3, 
        //Rev LL: 3,2,1 here we were sending 3 (prev) but instead of that for this question we will send 1 so that means head intead of prev;
        return {newTail, newHead};
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr || k == 1) return head;
        int count = 0;
        ListNode* temp = head;
        ListNode* newHead = head;
        bool firstGroup = true;
        //pg is previous group tail
        ListNode* pgtail = nullptr;
        while(temp != nullptr){
            count++;
            if(count == k){
                ListNode* front = temp->next;
                temp->next = nullptr;
                //it.first is newTail and it.second is new head
                auto it = reverseLL(newHead);
                if(firstGroup){
                    head = it.second;
                    firstGroup = false;
                }
                if(pgtail != nullptr) pgtail->next = it.second;
                pgtail = it.first;
                pgtail->next = front;
                newHead = front;
                temp = front;
                count = 0;
            }else{
                temp = temp->next;
            }
        }
        return head;
    }
};
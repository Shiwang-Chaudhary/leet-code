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

    ListNode* reverseLL(ListNode* head){
        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* front = nullptr;
        while(curr != nullptr){
            front = curr->next;
            curr->next = prev;
            prev = curr;
            curr = front;
        }
        return prev;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //Brute force: TC: O(3n) and SC: O(1)
        // if(head == nullptr || head->next == nullptr) return nullptr;
        // ListNode* temp = head;
        // ListNode* revHead = reverseLL(temp);
        // if(n == 1){
        //     revHead = revHead->next;
        //     head = reverseLL(revHead);
        //     return head;
        // }
        // int count = 0;
        // ListNode* current = revHead;
        // while(current != nullptr){
        //     count++;
        //     if(count == n-1){
        //         current->next = current->next->next;
        //         break;
        //     }
        //     current = current->next;
        // }
        // head = reverseLL(revHead);
        // return head;

        //Brute solution 2: TC: O(n) and SC: O(1)
        // if(head == nullptr || head->next == nullptr) return nullptr;
        // int size = 0;
        // ListNode* temp = head;
        // while(temp != nullptr){
        //     size++;
        //     temp = temp->next;
        // }
        // int newPos = size - n + 1;
        // temp = head;
        // if(newPos == 1){
        //     head = head->next;
        //     return head;
        // }
        // int count = 0;
        // while(temp != nullptr){
        //     count++;
        //     if(count == newPos-1){
        //         temp->next = temp->next->next;
        //         break;
        //     }
        //     temp = temp->next;
        // }
        // return head;

        //Optimal solution: TC: O(n) and SC: O(1)
        if(head == nullptr || head->next == nullptr) return nullptr;
        ListNode* fast = head;
        for(int i = 0; i < n; i++){
            fast = fast->next;
        }
        //if n = size of LL then fast becomes null and that happens only when we have to delete the head node, so:
        if(fast == nullptr) return head = head->next;
        ListNode* slow = head;
        //since fast == nullptr condition is already handled we dont need to use fast!=nullptr in while loop and since we are moving fast for 1 element at a time, fast will never be nullptr before the end of loop...
        while(fast->next != nullptr){
            slow = slow->next;
            fast = fast->next;
        }
        slow->next = slow->next->next;
        return head;
    }
};
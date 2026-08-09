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
    ListNode* deleteMiddle(ListNode* head) {
        //Brute force: TC: O(2n) and SC: O(1)
        // if (head == nullptr) return nullptr;
        // int size = 0;
        // ListNode* temp = head;
        // while(temp != nullptr){
        //     size++;
        //     temp = temp->next;
        // }
        // if(head->next == nullptr) return nullptr;
        // temp = head;
        // int count = 0;
        // int mid = size/2 + 1;
        // while(temp != nullptr){
        //     count++;
        //     if(count == mid - 1){
        //         temp->next = temp->next->next;
        //         break;
        //     }
        //     temp = temp->next;
        // }
        // return head;

        //Optimal solution: TC: O(n) and SC: O(1)
        if(head == nullptr || head->next == nullptr) return nullptr;
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* back = slow;
        while(fast != nullptr && fast->next != nullptr){
            back = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        back->next = back->next->next;
        return head;
    }
};
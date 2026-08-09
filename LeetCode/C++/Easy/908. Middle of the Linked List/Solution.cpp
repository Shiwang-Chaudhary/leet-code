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
    ListNode* middleNode(ListNode* head) {
        //Brute force: O(2n) and SC: O(1)
        // ListNode* temp = head;
        // int count = 0;
        // int size = 0;
        // while(temp != nullptr){
        //     size++;
        //     temp = temp->next;
        // }
        // int mid = size/2 + 1;
        // temp = head;
        // while(temp != nullptr){
        //     count++;
        //     if(count == mid){
        //         head = temp;
        //     }
        //     temp = temp->next;
        // }
        // return head;

        //Optimal approach: TC: O(n) and SCL O(1)
        ListNode* slow = head; //moves by 1
        ListNode* fast = head; //moves by 2
        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        head = slow;
        return head;
    }
};
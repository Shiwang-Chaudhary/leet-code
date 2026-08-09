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
        ListNode* temp = head;
        int count = 0;
        int size = 0;
        while(temp != nullptr){
            size++;
            temp = temp->next;
        }
        int mid = size/2 + 1;
        temp = head;
        while(temp != nullptr){
            count++;
            if(count == mid){
                head = temp;
            }
            temp = temp->next;
        }
        return head;
    }
};
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
    ListNode* rotateRight(ListNode* head, int k) {
        //There could be different implementation of this algo but core logic is same as this one
        //Optimal solution: TC: O(2n) and SC: O(1)
        if(head == nullptr) return head;
        ListNode* last = head;
        int size = 0;
        ListNode* reqNode = head;
        while(last->next != nullptr){
            size++;
            last = last->next;
        }
        //Total size of LL and last points to the last node of LL
        size = size + 1; // we did +1 because we didnt include lastnode in size
        //we need to be on this position...
        int rot = k % size;
        //if rotations are same as size then no need to do any rotation and just return head
        if(rot == 0) return head;
        int steps = size - rot;
        int count = 0;
        //Now it becomes a circular LL
        last->next = head;
        while(count <= steps){
            count++;
            if(count == steps){
                //New head
                head = reqNode->next;
                reqNode->next = nullptr;
                break;
            }else{
                reqNode = reqNode->next;
            }
        }
        return head;
    }
};
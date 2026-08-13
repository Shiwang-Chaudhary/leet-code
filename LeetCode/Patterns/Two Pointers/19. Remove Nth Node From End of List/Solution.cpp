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
        if(head == nullptr || head->next == nullptr) return nullptr;
        ListNode* temp = head;
        ListNode* revHead = reverseLL(temp);
        if(n == 1){
            revHead = revHead->next;
            head = reverseLL(revHead);
            return head;
        }
        int count = 0;
        ListNode* current = revHead;
        while(current != nullptr){
            count++;
            if(count == n-1){
                current->next = current->next->next;
                break;
            }
            current = current->next;
        }
        head = reverseLL(revHead);
        return head;
    }
};
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
    ListNode* reverseList(ListNode* head) {
        //Brute force: TC:O(n) and SC:O(1)
        // stack<int> st;
        // ListNode* temp = head;
        // while(temp != nullptr){
        //     st.push(temp->val);
        //     temp = temp->next;
        // }
        // temp = head;
        // while(temp != nullptr){
        //     int el = st.top();
        //     st.pop();
        //     temp->val = el;
        //     temp = temp->next;
        // }
        // return head;



        ListNode* curr = head;
        ListNode* front = NULL;
        ListNode* prev = NULL;
        while(curr != nullptr){
            front = curr->next;
            curr->next = prev;
            prev = curr;
            curr = front;
        }
        head = prev;
        return head;
    }
};
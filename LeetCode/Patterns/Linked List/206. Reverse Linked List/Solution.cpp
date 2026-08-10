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
        //Brute force: TC:O(2n) and SC:O(n) because of stack
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


        //Optimal solution: TC: O(n) and SC:O(1)
        //Also called Three pointer approach or Iterative approach
        // ListNode* curr = head;
        // ListNode* front = NULL;
        // ListNode* prev = NULL;
        // while(curr != nullptr){
        //     front = curr->next;
        //     curr->next = prev;
        //     prev = curr;
        //     curr = front;
        // }
        // head = prev;
        // return head;

        //Good for learning:
        //Recursion approach: TC:O(n) and SC:O(n) because of recursion stack
        if(head == nullptr || head->next == nullptr) return head;
        ListNode* newHead = reverseList(head->next);
        ListNode* front = head->next;
        front->next = head;
        head->next = nullptr;
        return newHead;
    }
};
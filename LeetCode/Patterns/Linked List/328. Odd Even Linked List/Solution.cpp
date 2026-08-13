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
    ListNode* oddEvenList(ListNode* head) {

        // if(head == nullptr || head->next == nullptr) return head;
        // vector<int> odd;
        // vector<int> even;
        // ListNode* temp = head;
        // int count = 1;
        // // Storing odd and even values
        // while(temp != nullptr){
        //     if(count % 2 == 1)
        //         odd.push_back(temp->val);
        //     else
        //         even.push_back(temp->val);

        //     count++;
        //     temp = temp->next;
        // }
        // //Write odd values first
        // temp = head;
        // for(int i = 0; i < odd.size(); i++){
        //     temp->val = odd[i];
        //     temp = temp->next;
        // }

        // // Then write even values
        // for(int i = 0; i < even.size(); i++){
        //     temp->val = even[i];
        //     temp = temp->next;
        // }

        // return head;


        //Optimal solution: TC: O(2n) and SC: O(1), i came up with this approach myself but its longer and uses TC: O(2n)
        // int count = 0;
        // if(head == nullptr || head->next == nullptr) return head;
        // ListNode* odd = head;
        // ListNode* even = head->next;
        // ListNode* evenHead = head->next;
        // ListNode* temp = head;
        // while(temp != nullptr){
        //     count++;
        //     ListNode* front = temp->next;
        //     if(count%2 == 1){
        //         if(odd->next != nullptr) odd->next = odd->next->next;
        //         odd = odd->next;
        //     }else{
        //         if(even->next != nullptr) even->next = even->next->next;
        //         even = even->next;
        //     }
        //     temp = front;
        // }
        // temp = head;
        // while(temp->next != nullptr){
        //     temp = temp->next;
        // }
        // temp->next = evenHead;
        // return head;

        //Optimal approach: TC: O(n) and SC: O(1)
        if(head == nullptr || head->next == nullptr) return head;
        ListNode* even = head->next;
        ListNode* odd = head;
        ListNode* evenHead = even;
        //we use even->next != nullptr to avoid odd becoming nullptr, do a dry, it will make sense...
        while(even != nullptr && even->next != nullptr){
            odd->next = even->next;
            odd = odd->next;

            even->next = odd->next;
            even = even->next;
        }
        //odd points to last node of odd chain
        odd->next = evenHead;
        return head;
    }
};
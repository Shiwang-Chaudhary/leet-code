/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:

    bool find(vector<ListNode*>& v, ListNode* target){
        if(v.empty()) return false;
        for(int i = 0; i < v.size(); i++){
            if(v[i] == target) return true;
        }
        return false;
    }
    ListNode *detectCycle(ListNode *head) {
        //Brute solution: TC: O(n) and SC: O(n)
        // ListNode* temp = head;
        // unordered_set<ListNode*> st;
        // while(temp != nullptr){
        //     if(st.find(temp) != st.end()){
        //         return temp;
        //     }
        //     st.insert(temp);
        //     temp = temp->next;
        // }
        // return nullptr;

        //Optimal solution: TC: O(n) and SC: O(1)
        //In striver method, he write other loop inside first loop but TC is O(n) because second loop only runs 1 time at most O(n), so outer + inner loop TC will be O(n) + O(n) (runs one time), so TC: O(2n) or O(n)
        if(head == nullptr || head->next == nullptr) return nullptr;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
            //if slow and fast points to same node then there is loop in LL
            if(slow == fast) break;
        }
        //return null if cycle doesnt exist
        if(fast == nullptr || fast->next == nullptr) return nullptr;
        slow = head;

        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
        }
        return slow; // fast
    }
};
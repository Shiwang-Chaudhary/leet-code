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

    bool hasCycle(ListNode *head) {
        //Brute solution: TC: O(n^2) and SC: O(n)
    //    ListNode* temp = head;
    //    vector<ListNode*> v;
    //    while(temp != nullptr){
    //         if(find(v, temp)){
    //             return true;
    //         }
    //         v.push_back(temp);
    //         temp = temp->next;
    //    }
    //    return false;

        //Better solution: TC: O(n) and SC: O(n)
        // ListNode* temp = head;
        // unordered_set<ListNode*> st;
        // while(temp != nullptr){
        //     if(st.find(temp) != st.end()){
        //         return true;
        //     }
        //     st.insert(temp);
        //     temp = temp->next;
        // }
        // return false;

        //Optimal solution: TC: O(n) and SC: O(1)
        ListNode* temp = head;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) return true;
        }
        return false;
    }
};
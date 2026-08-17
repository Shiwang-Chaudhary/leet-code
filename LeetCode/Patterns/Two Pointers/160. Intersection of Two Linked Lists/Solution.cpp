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
    void store(vector<ListNode*>& v, ListNode* head){
        ListNode* temp = head;
        while(temp != nullptr){
            v.push_back(temp);
            temp = temp->next;
        }
    }
    bool exist(ListNode* temp, vector<ListNode*>& v){
        for(int i = 0; i < v.size(); i++){
            if(temp == v[i]){
                return true;
            }
        }
        return false;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        vector<ListNode*> v;
        if(headA == nullptr || headB == nullptr) return nullptr;
        ListNode* temp1 = headA;
        ListNode* temp2 = headB;
        store(v, temp1);
        while(temp2 != nullptr){
            if(exist(temp2, v)){
                return temp2;
            }
            temp2 = temp2->next;
        }
        return nullptr;
    }
};
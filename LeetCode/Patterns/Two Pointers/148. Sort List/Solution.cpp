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

    ListNode* merge(ListNode* list1, ListNode* list2){
        if(list1 == nullptr) return list2;
        if(list2 == nullptr) return list1;
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;
        while(temp1 != nullptr && temp2 != nullptr){
            if(temp1->val < temp2->val){
                curr->next = temp1;
                curr = curr->next;
                temp1 = temp1->next;
            }else{
                curr->next = temp2;
                curr = curr->next;
                temp2 = temp2->next;
            }
        }
        while(temp1 != nullptr){
            curr->next = temp1;
            curr = curr->next;
            temp1 = temp1->next;
        }
        while(temp2 != nullptr){
            curr->next = temp2;
            curr = curr->next;
            temp2 = temp2->next;
        }
        return dummy->next;
    }

    ListNode* sortList(ListNode* head) {
        //Brute force: O(nlogn) and SC: O(n)
        // if(head == nullptr || head->next == nullptr) return head;
        // vector<int> v;
        // ListNode* temp = head;
        // while(temp != nullptr){
        //     v.push_back(temp->val);
        //     temp = temp->next;
        // }
        // sort(v.begin(), v.end());
        // temp = head;
        // int i = 0;
        // while(temp != nullptr && i < v.size()){
        //     temp->val = v[i];
        //     i++;
        //     temp = temp->next;
        // }
        // return head;

        //Optimal solution: 
        if(head == nullptr) return head;
        if(head->next == nullptr) return head;
        ListNode* start = head;
        ListNode* slow = head;
        ListNode* fast = head->next;
        // ListNode
        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        //slow is now the middle element
        //we have to split the function with slow element now...
        ListNode* nextMid = slow->next;
        slow->next = nullptr;
        ListNode* head1 = sortList(start);
        ListNode* head2 = sortList(nextMid);
        head = merge(head1, head2);
        return head;
    }
};
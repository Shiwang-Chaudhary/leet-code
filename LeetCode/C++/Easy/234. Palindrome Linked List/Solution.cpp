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
    //For brute force solution:
    void convertToVector(ListNode* head, vector<int>& v){
        ListNode* temp = head;
        while(temp != nullptr){
            v.push_back(temp->val);
            temp = temp->next;
        }
    }
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
    bool isPalindrome(ListNode* head) {
        //Brute force 1: TC: O(4n) and SC: O(2n)
        // vector<int> v1;
        // vector<int> v2;
        // convertToVector(head, v1);
        // ListNode* newHead = reverseLL(head);
        // convertToVector(newHead, v2);
        // for(int i = 0; i < v1.size(); i++){
        //     if(v1[i] != v2[i]) return false;
        // }
        // return true;

        //Brute force 2: TC:O(2n) and SC:O(n)
        // vector<int> v1;
        // convertToVector(head, v1);
        // int left = 0;
        // int right = v1.size() - 1;
        // while(left < right){
        //     if(v1[left] == v1[right]){
        //         left++;
        //         right--;
        //     }else{
        //         return false;
        //     }
        // }
        // return true;

        //Optimal solution: TC: O(n) and SC: O(1)
        if(head == nullptr || head->next == nullptr) return true;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        //slow now points to the middle element:
        //so reverse the LL from slow to end and compare element one by one like two pointers:
        ListNode* last = reverseLL(slow);
        //After reversing, list is like this:
        //1->2->2<-1 but 3rd element points to null since its the last element in reverse,
        //we can check that in reverseLL function...
        ListNode* temp = head;
        while(last != nullptr){
            if(temp->val == last->val){
                temp = temp->next;
                last = last->next;
            }else return false;
        }
        return true;
    }
};
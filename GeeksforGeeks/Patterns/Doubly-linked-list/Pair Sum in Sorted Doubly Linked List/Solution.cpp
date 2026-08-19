/* Structure of Doubly Linked List Node
class Node {
  public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
}; */

class Solution {
  public:
    vector<vector<int>> givenSumPairs(Node* head, int target) {
        //Since list is sorted we can use two pointers approach:
        vector<vector<int>> ans;
        Node* temp = head;
        while(temp->next != nullptr){
            temp = temp->next;
        }
        Node* left = head;
        Node* right = temp;
        while(left != right && left->prev != right){
            int sum = left->data + right->data;
            if(sum == target){
                ans.push_back({left->data, right->data});
                left = left->next;
                right = right->prev;
            }else if(sum > target){
                //we need to reduce the sum value so,
                right = right->prev;
            }else{
                //sum < target
                //we need to increace the sum value
                left = left->next;
            }
        }
        return ans;
    }
};
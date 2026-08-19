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
        //Brute force: TC: O(n^2) and SC: O(1)
        // vector<vector<int>> ans;
        // for (Node* first = head; first != nullptr; first = first->next) {
        //     for (Node* second = first->next; second != nullptr; second = second->next) {
        //         if (first->data + second->data == target) {
        //             ans.push_back({first->data, second->data});
        //         }
        //     }
        // }
        // return ans;
        
        //Better solution: TC: O(n) and SC: O(n)
        //Hashset solution:
        // vector<vector<int>> ans;
        // unordered_set<int> st;
        // Node* temp = head;
        // while (temp != nullptr) {
        //     int remaining = target - temp->data;
        //     if (st.find(remaining) != st.end()) {
        //         ans.push_back({remaining, temp->data});
        //     }
        //     st.insert(temp->data);
        //     temp = temp->next;
        // }
        // return ans;
        
        //Optimal solution: TC: O(n) and SC: O(1)
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
/* Structure of Linked List Node
class Node {
 public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};*/

class Solution {
  public:
    int lengthOfLoop(Node *head) {
        //Brute solution: TC: O(2n) and SCL O(n)
        // int count = 0;
        // unordered_set<Node*> st;
        // unordered_set<Node*> st2;
        // Node* temp = head;
        // Node* start = nullptr;
        // while(temp != nullptr){
        //     if(st.find(temp) != st.end()){
        //         start = temp;
        //         count++;
        //         //since this loop runs only one time at most n times so total TC will be O(n) + O(n)
        //         while(temp->next != start){
        //             count++;
        //             temp = temp->next;
        //         }
        //         break;
        //     }
        //     st.insert(temp);
        //     temp = temp->next;
        // }
        // return count;

        //Optimal solution: TC: O(2n) and SC: O(1)
        if(head == nullptr) return 0;
        int count = 0;
        Node* slow = head;
        Node* fast = head;
        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                //means loop exist...
                //we dont really need to find the starting point of the loop because we need to find the length of it, and since slow and fast are equal that means loop exist and we can just iterate over it until fast->next != slow to find the length...
                count++;
                while(fast->next != slow){
                    count++;
                    fast = fast->next;
                }
                break;
            }
        }
        return count;
    }
};
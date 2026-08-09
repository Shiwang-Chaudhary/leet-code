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
};

*/
class Solution {
  public:
    Node *reverse(Node *head) {
        // stack<int> st;
        // Node* temp = head;
        // while(temp!=nullptr){
        //     st.push(temp->data);
        //     temp = temp->next;
        // }
        // temp = head;
        // while(temp != nullptr){
        //     int element = st.top();
        //     st.pop();
        //     temp->data = element;
        //     temp = temp->next;
        // }
        // return head;
        Node* last = nullptr;
        while(head != nullptr){
            last = head;
            Node* front = head->next;
            head->next = head->prev;
            head->prev = front;
            
            head = front;
        }
        return last;
    }
};
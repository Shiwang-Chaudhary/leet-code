/* Structure of a link list node
class Node {
  public:
    int data;
    Node* next;
    Node* prev;
    Node(int value) {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};
*/
class Solution {
  public:
    Node* removeDuplicates(Node* head) {
        // code here
        unordered_set<int> st;
        Node* temp = head;
        while(temp != nullptr){
            Node* front = temp->next;
            Node* back = temp->prev;
            if(st.find(temp->data) != st.end()){
                if(back != nullptr) back->next = front;
                if(front != nullptr) front->prev = back;
                temp = front;
            }else{
                st.insert(temp->data);
                temp = temp->next;
            }
        }
        return head;
    }
};
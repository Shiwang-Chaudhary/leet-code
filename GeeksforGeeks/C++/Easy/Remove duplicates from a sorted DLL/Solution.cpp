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
        //Better solution: TC: O(n) and SC: O(n)
        // unordered_set<int> st;
        // Node* temp = head;
        // while(temp != nullptr){
        //     Node* front = temp->next;
        //     Node* back = temp->prev;
        //     if(st.find(temp->data) != st.end()){
        //         if(back != nullptr) back->next = front;
        //         if(front != nullptr) front->prev = back;
        //         temp = front;
        //     }else{
        //         st.insert(temp->data);
        //         temp = temp->next;
        //     }
        // }
        // return head;
        
        //Optimal solution: TC: O(n) and SC: O(1)
        Node* temp = head;
        while(temp != nullptr && temp->next != nullptr){
            Node* front = temp->next;
            Node* back = temp->prev;
            if(temp->data == front->data){
                temp->next = front->next;
                if(temp->next != nullptr) temp->next->prev = temp;
                //No need to remove temp ahead because the next duplicate is deleted now
            }else{
                temp = temp->next;
            }
        }
        return head;
    }
};
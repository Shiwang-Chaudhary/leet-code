/* a Node of the doubly linked list
class Node {
  public:
    int data;
    Node* next;
    Node* prev;

    Node(int x) {
        data = x;
        next = nullptr;
        prev = nullptr;
    }
};*/

class Solution {
  public:
    Node* deleteAllOccurOfX(Node* head, int x) {
        // code here
        if(head == nullptr) return nullptr;
        while(head && head->data == x){
            head = head->next;
            if(head) head->prev = nullptr;
        }
        Node* temp = head;
        while(temp != nullptr){
            if(temp->data == x){
                Node* front = temp->next;
                Node* back = temp->prev;
                if(back != nullptr) back->next = front;
                if(front != nullptr) front->prev = back;
                temp = front;
            }else{
                temp = temp->next;
            }
        }
        return head;
    }
};
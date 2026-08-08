/* Structure of Doubly Linked List Node
class Node {
  public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
*/

class Solution {
  public:
    Node* delPos(Node* head, int x) {
        if(head == nullptr) return NULL;
        if(x == 1){
            Node* temp = head;
            head = head->next;
            if(head != nullptr) head->prev = nullptr;
            delete temp;
            return head;
        }
        Node* temp = head;
        int count = 0;
        while(temp != nullptr){
            count++;
            if(count == x){
                if(temp->prev != nullptr)temp->prev->next = temp->next;
                if(temp->next != nullptr)temp->next->prev = temp->prev;
                delete temp;
                break;
            }
            temp = temp->next;
        }
        return head;
    }
};
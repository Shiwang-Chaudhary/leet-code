/* Structure of linked list Node
class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    
    Node* reverseLL(Node* head){
        Node* curr = head;
        Node* front = nullptr;
        Node* prev = nullptr;
        while(curr != nullptr){
            front = curr->next;
            curr->next = prev;
            prev = curr;
            curr = front;
        }
        return prev;
    }
  
    Node* addOne(Node* head) {
        int carry = 1;
        Node* temp = head;
        Node* revHead = reverseLL(temp);
        temp = revHead;
        Node* prev = temp;
        while(temp != nullptr){
            int sum = temp->data + carry;
            int digit = sum % 10;
            carry = sum / 10;
            temp->data = digit;
            prev = temp;
            temp = temp->next;
        }
        if(carry != 0){
            Node* lastNode = new Node(carry);
            prev->next = lastNode;
        }
        head = reverseLL(revHead);
        return head;
    }
};
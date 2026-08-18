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
    
    int func(Node* head){
        if(head == nullptr) return 1;
        int carry = func(head->next);
        int sum = carry + head->data;
        int digit = sum % 10;
        head->data = digit;
        carry = sum / 10;
        return carry;
    }
  
    Node* addOne(Node* head) {
        //Optimal solution: TC: O(n) and SC: O(1)
        // int carry = 1;
        // Node* temp = head;
        // Node* revHead = reverseLL(temp);
        // temp = revHead;
        // Node* prev = temp;
        // while(temp != nullptr){
        //     int sum = temp->data + carry;
        //     int digit = sum % 10;
        //     carry = sum / 10;
        //     temp->data = digit;
        //     prev = temp;
        //     temp = temp->next;
        // }
        // if(carry != 0){
        //     Node* lastNode = new Node(carry);
        //     prev->next = lastNode;
        // }
        // head = reverseLL(revHead);
        // return head;
        
        //Not optimal: O(n) and SC: O(1)
        Node* temp = head;
        int carry = func(temp);
        if (carry) {
            Node* newNode = new Node(carry);
            newNode->next = head;
            head = newNode;
        }
        return head;
    }
};
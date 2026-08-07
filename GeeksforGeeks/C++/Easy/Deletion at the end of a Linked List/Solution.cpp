/*
class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/
class Solution {
  public:
    Node* removeLastNode(Node* head) {
        if(head == NULL || head->next == NULL) return NULL;
        Node* temp = head;
        while(temp->next->next != nullptr){
            temp = temp->next;
        }
        Node* garbage = temp->next;
        delete garbage;
        temp->next = nullptr;
        return head;
    }
};
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/
class Solution {
public:

    Node* recursiveFun(Node* head) {
        if (head == nullptr) return nullptr;

        Node* temp = head;

        while (temp != nullptr) {

            if (temp->child != nullptr) {

                Node* front = temp->next;
                Node* child = temp->child;

                Node* tail = recursiveFun(child);

                temp->next = child;
                child->prev = temp;

                if (front != nullptr) {
                    tail->next = front;
                    front->prev = tail;
                }

                temp->child = nullptr;

                if (front == nullptr)
                    return tail;

                temp = front;

            } else {

                if (temp->next == nullptr)
                    return temp;

                temp = temp->next;
            }
        }

        return nullptr;
    }

    Node* flatten(Node* head) {
        if (head == nullptr) return nullptr;

        recursiveFun(head);

        return head;
    }
};
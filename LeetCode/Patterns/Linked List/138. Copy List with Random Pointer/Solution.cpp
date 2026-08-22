/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        //Brute solution: TC: O(2n) and SC:O(2n) (hashmap and LL) techincally only O(n) because new LL is just for answer
        // Node* temp = head;
        // Node* dummy = new Node(-1);
        // Node* mover = dummy;
        //          //Original:Copy
        // unordered_map<Node*, Node*> mp;
        // while(temp != nullptr){
        //     Node* newNode = new Node(temp->val);
        //     mp[temp] = newNode;
        //     mover->next = newNode;
        //     temp = temp->next;
        //     mover = mover->next;
        // }
        // //Now we have stored Orignal add to Copied address, now we can find the random node for copied list
        // temp = head;
        // Node* newTemp = dummy->next;
        // while(temp != nullptr){
        //     Node* copyRandomNode = mp[temp->random];
        //     newTemp->random = copyRandomNode;
        //     newTemp = newTemp->next;
        //     temp = temp->next;
        // }
        // return dummy->next;

        //Optimal solution: O(n) and SC: O(1) but O(n) if we include the answer LL
        Node* temp = head;
        Node* dummy = new Node(-1);
        Node* mover = dummy;
        while(temp != nullptr){
            Node* front = temp->next;
            Node* newNode = new Node(temp->val);
            temp->next = newNode;
            newNode->next = front;
            temp = front;
        }
        temp = head;
        while(temp != nullptr){
            Node* copyNode = temp->next;
            Node* randomCopynode = (temp->random != nullptr) ? temp->random->next : nullptr;
            copyNode->random = randomCopynode;
            temp = temp->next->next;
        }
        temp = head;
        while(temp != nullptr){
            mover->next = temp->next;
            mover = mover->next;
            temp->next = temp->next->next;
            temp = temp->next;
        }
        return dummy->next;
    }
};
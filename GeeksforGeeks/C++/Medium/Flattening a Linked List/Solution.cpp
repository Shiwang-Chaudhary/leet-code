/* Structure of Linked List Node
class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = nullptr;
        bottom = nullptr;
    }
};*/

class Solution {
  public:
    
    Node* convertLL(vector<int>& v){
        int size = v.size();
        if(size == 0) return nullptr;
        Node* head = new Node(v[0]);
        Node* temp = head;
        for(int i = 1; i < size; i++){
            Node* newNode = new Node(v[i]);
            temp->bottom = newNode;
            temp = temp->bottom;
        }
        return head;
    }
        
    Node* mergeLL(Node* l1, Node* l2){
        if(l1 == nullptr) return l2;
        if(l2 == nullptr) return l1;
        Node* dummy = new Node(-1);
        Node* curr = dummy; //dummy node mover
        Node* temp1 = l1;
        Node* temp2 = l2;
        while(temp1 != nullptr && temp2 != nullptr){
            if(temp1->data < temp2->data){
                curr->bottom = temp1;
                curr = curr->bottom;
                curr->next = nullptr;
                temp1 = temp1->bottom;
            }else{
                curr->bottom = temp2;
                curr = curr->bottom;
                curr->next = nullptr;
                temp2 = temp2->bottom;
            }
        }
        //For remaining elements:
        curr->bottom = temp1 != nullptr ? temp1 : temp2;
        //We need to use this loop to do next = nullptr in remaining elements...
        while (curr->bottom != nullptr) {
            curr = curr->bottom;
            curr->next = nullptr;
        }
        return dummy->bottom;
    }
    
    Node* recFun(Node* head){
        if(head == nullptr || head->next == nullptr) return head;
        Node* l2 = recFun(head->next);
        Node* combineHead = mergeLL(head, l2);
        return combineHead;
    }
    
    Node* flatten(Node* head) {
        // code here
        //Brute force: TC: O(nlogn) and SC: O(n)
        //Here n is total number of nodes in the LL...
        // if(head == nullptr) return nullptr;
        // Node* temp = head;
        // vector<int> v;
        // while(temp != nullptr){
        //     Node* t2 = temp;
        //     while(t2 != nullptr){
        //         v.push_back(t2->data);
        //         t2 = t2->bottom;
        //     }
        //     temp = temp->next;
        // }
        // //Now we have all the elements in array:
        // sort(v.begin(), v.end());
        // //Conver this array into LL with bottom pointer only
        // head = convertLL(v);
        // return head;
        
        
        if(head == nullptr || head->next == nullptr) return head;
        return recFun(head);
        
    }
};
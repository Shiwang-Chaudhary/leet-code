class MyQueue {
    stack<int> s1;
    //basically s2 represent the queue elements
    stack<int> s2;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        //Approach 1: Costly push...
        //TC: O(2n) where n is the current size of stack
        //SC: 2 dynamic stacks
        // while(!s1.empty()){
        //     s2.push(s1.top());
        //     s1.pop();
        // }
        // s1.push(x);
        // while(!s2.empty()){
        //     s1.push(s2.top());
        //     s2.pop();
        // }

        //Approach 2: Costly pop/top approach... (recommended)
        s1.push(x);
    }
    
    int pop() {
        // int element = s1.top();
        // s1.pop();
        // return element;

        if(!s2.empty()){
            int element = s2.top();
            s2.pop();
            return element;
        }else{
            //put all elements of s1 to s2 and remove top element
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            int element = s2.top();
            s2.pop();
            return element;
        }
    }
    
    int peek() {
        // return s1.top();

        //s2 basically represent the queue elements, if its not empty then pop from s2
        if(!s2.empty()){
            return s2.top();
        }else{
            //if s2 is empty then put s1 element into s2 and then pop from it
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            return s2.top();
        }
    }
    
    bool empty() {
        //because element might still be in s1 and s2 can be empty so we need to check for both
        return s1.empty() && s2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
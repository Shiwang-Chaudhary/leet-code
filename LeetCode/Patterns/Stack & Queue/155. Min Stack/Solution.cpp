class MinStack {
    stack<int> st1;
    stack<int> st2;
public:
    MinStack() {
        
    }
    
    void push(int value) {
        st1.push(value);
        if(!st2.empty()){
            //this will store duplicate minimum element but we dont have to worry about it since if we do pop then duplicate element would be removed only and atleast one minimum element would be there
            st2.push(min(st2.top(), value));
        }else{
            st2.push(value);
        }
    }
    
    void pop() {
        st1.pop();
        st2.pop();
    }
    
    int top() {
        return st1.top();
    }
    
    int getMin() {
        return st2.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
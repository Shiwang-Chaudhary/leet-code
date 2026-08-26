class Solution {
  public:
    
    void insertStack(int x, stack<int>& st){
        if(st.empty() || x >= st.top()){
            st.push(x);
            return;
        }
        int temp = st.top();
        st.pop();
        insertStack(x, st);
        st.push(temp);
    }
    
    void sortStack(stack<int> &st) {
        if(st.empty()) return;
        int x = st.top();
        st.pop();
        sortStack(st);
        insertStack(x, st);
    }
};

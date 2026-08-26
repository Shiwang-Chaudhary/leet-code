class Solution {
  public:
    
    void insertBottom(int x, stack<int>& st){
        if(st.empty()){ 
            st.push(x);
            return;
        }
        int temp = st.top();
        st.pop();
        insertBottom(x, st);
        st.push(temp);
    }
    
    void reverseStack(stack<int> &st) {
        //Optimal solution if using recursion: O(n^2) and O(n)
        if(st.empty()) return;
        int x = st.top();
        st.pop();
        reverseStack(st);
        insertBottom(x, st);
    }
};
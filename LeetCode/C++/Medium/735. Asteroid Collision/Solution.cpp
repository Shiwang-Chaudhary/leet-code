class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        //Optimal solution: TC: O(n) and SC: O(n) 
        int n = a.size();
        stack<int> st;
        st.push(a[0]);
        for(int i = 1; i < n; i++){
            //if alive is true keep the next element otherwise dont
            bool alive = true;
            //current element and next element
            while(!st.empty() && st.top() > 0 && a[i] < 0){
                int ce = st.top(); //current element
                int ne = a[i]; //next element, i is representing next element index
                if(ce + ne < 0){
                    st.pop();
                }else if(ce + ne == 0){
                    st.pop();
                    //since we dont need to add next element, do alive false
                    alive = false;
                    break;
                }else{
                    //ce + ne > 0
                    //since we dont need to add next element, do alive false
                    alive = false;
                    break;
                }
            }
            if(alive){
                st.push(a[i]);
            }
        }
        int size = st.size();
        vector<int> ans(size);
        for(int i = size - 1; i >= 0; i--){
            ans[i] = st.top();
            st.pop();
        }
        return ans;
    }
};
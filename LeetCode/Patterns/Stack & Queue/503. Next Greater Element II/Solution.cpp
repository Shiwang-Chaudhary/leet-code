class Solution {
public:
    vector<int> nextGreaterElements(vector<int> &arr) {
        //Optimal solution: TC: O(n) and SC: O(1) [Auxilary]
        stack<int> st;
        int n = arr.size();
        vector<int> ans(n, -1);
        //No need to use double for loop here, just circulate using indexes
        // for(int i = n-1; i >= 0; i--){
        //     int ce = arr[i];
        //     while(!st.empty() && st.top() <= ce){
        //         st.pop();
        //     }
        //     //after this loop, either we get empty stack or top > ce
        //     if(!st.empty()){
        //         ans[i] = st.top();
        //     }
        //     st.push(ce);
        // }
        // for(int i = n-1; i >= 0; i--){
        //     int ce = arr[i];
        //     while(!st.empty() && st.top() <= ce){
        //         st.pop();
        //     }
        //     //after this loop, either we get empty stack or top > ce
        //     if(!st.empty()){
        //         ans[i] = st.top();
        //     }
        //     st.push(ce);
        // }

        for(int i = 2*n-1; i >= 0; i--){
            int index = i % n;
            int ce = arr[index];
            while(!st.empty() && st.top() <= ce){
                st.pop();
            }
            //after this loop, either we get empty stack or top > ce
            if(!st.empty()){
                ans[index] = st.top();
            }
            st.push(ce);
        }
        return ans;
    }
};
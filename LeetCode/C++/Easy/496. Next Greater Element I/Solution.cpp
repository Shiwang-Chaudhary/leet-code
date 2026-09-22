class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        //Brute force: TC: O(n1 * n2) and SC: O(n), auxilary: O(1)
        // int n1 = nums1.size();
        // int n2 = nums2.size();
        // vector<int> ans(n1, -1);
        // for(int i = 0; i < n1; i++){
        //     for(int j = 0; j < n2; j++){
        //         if(nums1[i] == nums2[j]){
        //             for(int k = j + 1; k < n2; k++){
        //                 if(nums2[k] > nums2[j]){
        //                     ans[i] = nums2[k];
        //                     break;
        //                 }
        //             }
        //         }
        //     }
        // }
        // return ans;

        //Optimal solution: TC: O(n1 + n2) and SC: O(n) (hashmaps)
        stack<int> st;
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<int> ans(n1);
        unordered_map<int,int> mp;
        for(int i = n2 - 1; i >= 0; i--){
            int ce = nums2[i]; //current element
            while(!st.empty() && st.top() < ce){
                st.pop();
            }
            if(!st.empty()){
                //top > ce (guranteed if stack isnt empty)
                mp[ce] = st.top();
            }else{
                mp[ce] = -1;
            }
            st.push(ce);
        }
        for(int i = 0; i < n1; i++){
            ans[i] = mp[nums1[i]];
        }
        return ans;
    }
};
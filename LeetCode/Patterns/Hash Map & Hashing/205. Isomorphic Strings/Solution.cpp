class Solution {
public:
    bool isIsomorphic(string s, string t) {
        // //Brute forece: TC: O(n^2) and SC: O(1)
        // int n = s.size();
        // if(n!= t.size()) return false;
        // //Outer for loop for current element
        // for(int i = 0; i < n; i++){
        //     //Inner for loop for accessing previous elements
        //     for(int j = 0; j < i; j++){
        //         //This is for s-->t mapping...
        //         //if current element exist before: s[i] == s[j] 
        //         //and previous element and current element of t string has different values: t[i]!=t[j], then return false
        //         if(s[i] == s[j] && t[i] != t[j]){
        //             return false;
        //         }
        //         //same as above but this for t-->s mapping...
        //         if(t[i] == t[j] && s[i]!=s[j]){
        //             return false;
        //         }
        //     }
        // }
        // return true;

        //Optimal solution: TC: O(n) and SC: O(1)
        unordered_map<char,char> st;
        unordered_map<char,char> ts;
        //Both s and t have same size.
        for(int i = 0; i < s.size(); i++){
            char sel = s[i];
            char tel = t[i];
            //check if sel exists in st if yes check if sel key points to current t[i] if it doesnt that means different configuration of same key
            if(st.find(sel) != st.end() && st[sel] != t[i]){
                return false;
            }
            //We need to check mapping for both s-->t and t-->s......
            //check if tel exists in ts if yes check if tel key points to current s[i] if it doesnt that means different configuration of same key
            if(ts.find(tel) != ts.end() && ts[tel] != s[i]){
                return false;
            }
            st[sel] = tel;
            ts[tel] = sel;
        }
        return true;
    }
};
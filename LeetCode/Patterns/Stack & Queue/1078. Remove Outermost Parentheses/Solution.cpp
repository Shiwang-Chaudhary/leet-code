class Solution {
public:
    string removeOuterParentheses(string s) {
        //Brute force: TC: O(n) and SC: O(n)
        // int balance = 0;
        // int start = 0;
        // string ans = "";
        // for(int i = 0; i < s.size(); i++){
        //     if(s[i] == '('){
        //         balance++;
        //     }else{
        //         balance--;
        //     }
        //     if(balance == 0){
        //         ans = ans + s.substr(start + 1, i - start - 1);
        //         start = i + 1;
        //     }
        // }
        // return ans;

        int balance = 0;
        string ans = "";
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                //Skip first iteration for (, otherwise add that element in the ans
                if(balance > 0){
                    ans.push_back(s[i]);
                }
                balance++;
            }else{
                //We need to do balance-- before the condition otherwise it will lead to add extra ) at the end 
                balance--;
                if(balance > 0){
                    ans.push_back(s[i]);
                }
            }
        }
        return ans;
    }
};
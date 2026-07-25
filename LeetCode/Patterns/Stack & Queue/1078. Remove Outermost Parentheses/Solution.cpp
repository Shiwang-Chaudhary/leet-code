class Solution {
public:
    string removeOuterParentheses(string s) {
        //
        int balance = 0;
        int start = 0;
        string ans = "";
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                balance++;
            }else{
                balance--;
            }
            if(balance == 0){
                ans = ans + s.substr(start + 1, i - start - 1);
                start = i + 1;
            }
        }
        return ans;
    }
};
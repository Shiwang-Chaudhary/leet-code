class Solution {
public:
    int open = 0;
    int close = 0;
    
    void recHelper(int n, string& s, vector<string>& v){
        if(open == n && close == n){
            v.push_back(s);
            return;
        }
        if(open < n){
            open++;
            s.push_back('(');
            recHelper(n, s, v);
            s.pop_back();
            open--;
        }
        if(close < open){
            close++;
            s.push_back(')');
            recHelper(n, s, v);
            s.pop_back();
            close--;
        }
    }

    vector<string> generateParenthesis(int n) {
        //Since we are generate different pattern, we caan perform backtracking
        vector<string> ans;
        string s;
        recHelper(n, s, ans);
        return ans;
    }
};
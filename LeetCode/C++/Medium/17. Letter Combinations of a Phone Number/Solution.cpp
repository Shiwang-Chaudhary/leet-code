class Solution {
public:

    void recHelper(int index, string& digits, string& temp, vector<string>& ans, vector<string>& letters){
        if(index == digits.size()){
            ans.push_back(temp);
            return;
        }
        int value = digits[index] - '0';
        string words = letters[value];
        for(auto c : words){
            temp.push_back(c);
            recHelper(index + 1, digits,temp, ans, letters);
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        //Optimal solution: TC: O(4^n × n) | SC: O(n) auxiliary space, O(4^n × n) including output
        vector<string> letters = {
            "", "", "abc", "def", "ghi", "jkl",
            "mno", "pqrs", "tuv", "wxyz"
        };
        string temp = "";
        vector<string> ans;
        recHelper(0, digits, temp, ans, letters);
        return ans;
    }
};
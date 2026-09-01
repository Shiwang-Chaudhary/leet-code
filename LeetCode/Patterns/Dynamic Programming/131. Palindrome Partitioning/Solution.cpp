class Solution {
public:

    bool isPalindrome(string& s, int left, int right){
        while(left < right){
            if(s[left] != s[right]) return false;
            left++;
            right--;
        }
        return true;
    }

    void recHelper(int index, string& s, vector<string>& temp, vector<vector<string>>& ans){
        if(index == s.size()){
            ans.push_back(temp);
            return;
        }
        for(int i = index; i < s.size(); i++){
            if(isPalindrome(s, index, i)){
                temp.push_back(s.substr(index, i - index + 1));
                recHelper(i + 1, s, temp, ans);
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<string> temp;
        vector<vector<string>> ans;
        recHelper(0, s, temp, ans);
        return ans;
    }
};
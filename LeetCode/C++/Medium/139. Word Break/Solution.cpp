class Solution {
public:

    bool recHelper(int index, string& s, vector<string>& dict){
        if(index == s.size()){
            return true;
        }
        string ans;
        for(int i = index; i < s.size(); i++){
            ans.push_back(s[i]);
            for(int j = 0; j < dict.size(); j++){
                if(ans == dict[j]){
                    if(recHelper(i+1, s, dict)){
                        return true;
                    }
                }
            }
        }
        return false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        //Brute force: TC: O(2^n * n * m) and SC: O(n + m), where m is the wordDict size...
        return recHelper(0, s, wordDict);
    }
};
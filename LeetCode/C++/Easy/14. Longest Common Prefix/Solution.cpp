class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string first = strs[0];
        for(int i = 0; i < first.size(); i++){
            for(int j = 0; j < strs.size(); j++){
                string el = strs[j];
                if(i > el.size()-1 || first[i] != el[i]){
                    if(i == 0){
                        return "";
                    }
                    return first.substr(0,i);
                }
            }
            
        }
        return first;
    }
};
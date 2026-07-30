class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string first = strs[0];
        //compare each element of first with every element of strs array
        for(int i = 0; i < first.size(); i++){
            for(int j = 0; j < strs.size(); j++){
                //compare ith element of first with ith element of strs[j]
                string el = strs[j];
                if(i > el.size()-1 || first[i] != el[i]){
                    //if first element isnt common then return empty string
                    if(i == 0){
                        return "";
                    }
                    return first.substr(0,i);
                }
            }
            
        }
        //We are returning first because there might be a case where all the elements in strs array have same value like strs = [abc,abc,abc] so in that case whole first is the answer
        return first;
    }
};
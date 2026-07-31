class Solution {
public:
    bool isAnagram(string s, string t) {
        //For this problem, using two unordered map is considered SC: O(1) because we are only talking about fix small 26 alphabets so this solution can be considered as optimal: TC: O(n) and SC: O(n) or O(1)
        // int n = s.size();
        // int m = t.size();
        // if(n != m) return false;
        // unordered_map<char,int> one;
        // unordered_map<char,int> two;
        // for(int i = 0; i < n; i++){
        //     one[s[i]]++;
        // }
        // for(int i = 0; i < n; i++){
        //     two[t[i]]++;
        // }
        // // for(int i = 0; i < n; i++){
        // //     if(one[s[i]] != two[s[i]]){
        // //         return false;
        // //     }
        // // }
        // //return true;
        // //OR
        // return one == two;

        //Optimal solution: TC: O(n) and SC: O(1)
        int freq[26] = {0};
        int n = s.size();
        int m = t.size();
        if(n != m) return false;
        //increase counter for specific alphabet in s string
        for(int i = 0; i < n; i++){
            freq[s[i] - 'a']++;
        }
        //decrease counter for specific alphabet in t string
        for(int i = 0; i < m; i++){
            freq[t[i] - 'a']--;
        }
        //if both string are anagram then all elements in freq array will be zero because they will cancel out each other
        for(int i = 0; i < 26; i++){
            if(freq[i] != 0) return false;
        }
        return true;
    }
};
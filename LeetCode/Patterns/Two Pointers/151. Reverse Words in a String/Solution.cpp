class Solution {
public:
    string reverseWords(string s) {
        //Brute: TC: O(n^2) because ans = ans + extra[i] creates a new string and copy the data to it so basically we are traversing and copying as well thats why its considered O(n^2) use chatgpt for more info, SC: O(n)

        //NOTE: ans+=extra[i] isnt same as ans = ans + extra[i], the second one considered as o(n^2) at the end of this problem on the other hand 1st one considered as o(n).
        // int n = s.size();
        // int start = 0;
        // vector<string> extra;
        // string ans;
        // for(int i = 0; i < n; i++){
        //     if(s[i] == ' '){
        //         string data = s.substr(start, i-start);
        //         if(data != ""){
        //             extra.push_back(data);
        //         }
        //         start = i + 1;
        //     }
        // }
        // //Remaining elements that doesnt have  " " at the end and even for those element that have more than one " " at the end:
        // string last = s.substr(start);
        // if(last != ""){
        //     extra.push_back(last);
        // }
        // for(int i = extra.size()-1; i >= 0; i--){
        //     ans += extra[i];
        //     if (i != 0) ans += " ";
        // }
        // return ans;


        //Optimal: TC: O(n) and SC: O(1)
        int n = s.size();
        int end = n - 1;
        string ans;
        int i;
        for (i = n - 1; i >= 0; i--) {
            if (s[i] == ' ') {
                int len = end - i;
                string word = s.substr(i + 1, len);
                if (!word.empty()) {
                    if (!ans.empty()) ans += ' ';
                    ans += word;
                }
                end = i - 1;
            }
        }
        //For handling the first word:
        string first = s.substr(i + 1, end + 1);
        if (!first.empty()) {
            if (!ans.empty()) ans += ' ';
            ans += first;
        }
        return ans;


        //Optimal solution 2: same tc and sc
        //Basically reversing whole string --> reversing word to make them look correct
        //--> removing extra space
        // reverse(s.begin(), s.end());
        // int n = s.size();
        // int start = 0;
        // while (start < n) {
        //     while (start < n && s[start] == ' ') start++;
        //     int end = start;
        //     while (end < n && s[end] != ' ') end++;
        //     reverse(s.begin() + start, s.begin() + end);
        //     start = end;
        // }
        // // Remove extra spaces
        // string ans;
        // int i = 0;
        // while (i < n) {
        //     while (i < n && s[i] == ' ') i++;
        //     if (i >= n) break;
        //     if (!ans.empty()) ans += ' ';
        //     while (i < n && s[i] != ' ') {
        //         ans += s[i];
        //         i++;
        //     }
        // }
        // return ans;
    }
};
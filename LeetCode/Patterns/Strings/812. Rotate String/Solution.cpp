class Solution {
public:
    bool rotateString(string s, string goal) {
        //Brute force: TC: O(n^2) and SC: O(n) because we are storing s inside original variable
        // int n = s.size();
        // string original = s;
        // if(s == goal) return true;
        // for(int i = 1; i < n; i++){
        //     //we are doing s = original because in each iteration we need original string instead of the one that we modified before.
        //     s = original;
        //     reverse(s.begin(), s.begin()+i);
        //     reverse(s.begin()+i, s.end());
        //     reverse(s.begin(), s.end());
        //     if(s == goal){
        //         return true;
        //     }
        // }
        // return false;


        //Optimal solution: TC: O(n) and SC: O(n)
        string newString = s+s;
        int size = s.size();
        for(int i = 0; i < newString.size(); i++){
            if(newString[i] == goal[0]){
                //could be the goal
                string sub = newString.substr(i, size);
                if(sub == goal) return true;
            }
        }
        return false;
    }
};
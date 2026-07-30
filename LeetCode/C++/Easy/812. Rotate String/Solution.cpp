class Solution {
public:

    // void rev(string &s){
    //     int n = s.size();
    //     int left = 0;
    //     int right = n-1;
    //     while(low < high){

    //     }
    // }

    bool rotateString(string s, string goal) {
        int n = s.size();
        string original = s;
        if(s == goal) return true;
        for(int i = 1; i < n; i++){
            //we are doing s = original because in each iteration we need original string instead of the one that we modified before.
            s = original;
            reverse(s.begin(), s.begin()+i);
            reverse(s.begin()+i, s.end());
            reverse(s.begin(), s.end());
            if(s == goal){
                return true;
            }
        }
        return false;
    }
};
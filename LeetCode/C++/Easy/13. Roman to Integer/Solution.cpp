class Solution {
public:
    int romanToInt(string s) {
        int n = s.size();
        unordered_map<char,int> mp;
        int ans = 0;
        int i = 0;
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;

        while(i < n-1){
            int current = mp[s[i]];
            int next = mp[s[i+1]];
            if(current >= next){
                ans = ans + current;
                i++;
            }else{
                int value = next - current;
                i = i+2;
                ans = ans + value;
            }
        }
        while(i < n){
            int current = mp[s[i]];
            ans = ans + current;
            i++;
        }
        return ans;
    }
};
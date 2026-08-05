class Solution {
public:

    int returnButyOfSubString(const string& s){
        int n = s.size();
        int minimum = INT_MAX;
        int maximum = 0;
        unordered_map<char,int> mp;
        for(int i = 0; i < n; i++){
            mp[s[i]]++;
        }
        for(auto it : mp){
            if(it.second > maximum){
                maximum = it.second;
            }
            if(it.second < minimum){
                minimum = it.second;
            }
        }
        return maximum - minimum;
    }

    int beautySum(string s) {
        int n = s.size();
        int sum = 0;
        for(int i = 0; i < n; i++){
            vector<int> freq(26,0);
            for(int j = i; j < n; j++){
                freq[s[j] - 'a']++;
                int mx = INT_MIN;
                int mn = INT_MAX;
                for(int k = 0; k < 26; k++){
                    if(freq[k] > 0){
                        mx = max(mx, freq[k]);
                        mn = min(mn, freq[k]);
                    }
                }
                sum = sum + (mx-mn);
            }
        }
        return sum;
    }
};
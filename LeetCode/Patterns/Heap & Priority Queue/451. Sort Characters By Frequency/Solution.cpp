class Solution {
public:
    string frequencySort(string s) {
        //Brute force: O(n^2) and SC:O(n)
        // string ans;
        // int n = s.size();
        // vector<pair<int,char>> v;
        // sort(s.begin(), s.end());
        // for(int i = 0; i < n; i++){
        //     int count = 0;
        //     for(int j = 0; j < n; j++){
        //         if(s[i] == s[j]) count++;

        //     }
        //     if(v.empty() || v.back().second != s[i]){
        //         v.push_back({count, s[i]});
        //     }
        // }
        // sort(v.begin(), v.end(), greater<pair<int, char>>());
        // for(auto it: v){
        //     ans.append(it.first, it.second);
        // }
        // return ans;

        //Better solution: 
        // int n = s.size();
        // priority_queue<pair<int,char>> pq;
        // unordered_map<char,int> freq;
        // string ans;
        // for(int i = 0; i < n; i++){
        //     freq[s[i]]++;
        // }
        // for(auto it: freq){
        //     pq.push({it.second, it.first});
        // }
        // while(!pq.empty()){
        //     auto top = pq.top();
        //     pq.pop();
        //     int freq = top.first;
        //     char el = top.second;
        //     ans.append(freq, el);
        // }
        // return ans;

        //Optimal solution :
        unordered_map<char,int> mp;
        string ans;
        int n = s.size();
        vector<vector<char>> bucket(n+1);
        for(int i = 0; i < s.size(); i++){
            mp[s[i]]++;
        }
        for(auto it: mp){
            bucket[it.second].push_back(it.first);
        }
        for(int i = n; i >= 1; i--){
            for(char c: bucket[i]){
                ans.append(i,c);
            }
        }
        return ans;
    }
};
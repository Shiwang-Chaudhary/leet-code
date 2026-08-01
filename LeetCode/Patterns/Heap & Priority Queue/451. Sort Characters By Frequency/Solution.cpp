class Solution {
public:
    string frequencySort(string s) {

        //Better solution: 
        int n = s.size();
        priority_queue<pair<int,char>> pq;
        unordered_map<char,int> freq;
        string ans;
        for(int i = 0; i < n; i++){
            freq[s[i]]++;
        }
        for(auto it: freq){
            pq.push({it.second, it.first});
        }
        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            int freq = top.first;
            char el = top.second;
            ans.append(freq, el);
        }
        return ans;
    }
};
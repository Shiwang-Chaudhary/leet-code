class Solution {
public:

    vector<int> convertToBinary(int num){
        vector<int> ans(32, 0);
        int i = 0;
        while(num > 0){
            ans[i] = num % 2;
            num = num/2;
            i++;
        }
        // reverse(ans.begin(), ans.end());
        return ans;
    }

    int minBitFlips(int start, int goal) {
        vector<int> s(32, 0);
        vector<int> g(32, 0);
        int count = 0;
        s = convertToBinary(start);
        g = convertToBinary(goal);
        for(int i = 0; i < s.size(); i++){
            if(s[i] != g[i]) count++;
        }
        return count;
    }
};
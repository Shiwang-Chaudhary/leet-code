class Solution {
public:
    int maxDepth(string s) {
        //Optimal solution: TC: O(n) and SC: O(1)
        int leftCnt = 0;
        int rightCnt = 0;
        int maximum = 0;
        for(int i = 1; i < s.size(); i++){
            if(s[i-1] == '('){
                leftCnt++;
            }else if(s[i-1] == ')'){
                rightCnt++;
            }
            maximum = max(maximum, leftCnt - rightCnt);
        }
        return maximum;
    }
};
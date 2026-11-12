class Solution {
public:

    int recursion(int r, int c, vector<vector<int>>& triangle){
        if(r == 0) return triangle[0][0];
        int up = INT_MAX;
        int upLeft = INT_MAX;
        if(c > 0) upLeft = triangle[r][c] + recursion(r-1, c-1, triangle);
        if(c < triangle[r-1].size()) up = triangle[r][c] + recursion(r-1, c, triangle);
        return min(upLeft, up);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int row = triangle.size();
        int col = triangle[row-1].size();
        int minans = INT_MAX;
        for(int i = 0; i < col; i++){
            minans = min(minans, recursion(row-1, i, triangle));
        }
        return minans;
    }
};
class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                bool left = (j == 0 || mat[i][j] > mat[i][j-1]);
                bool right = (j == col - 1 || mat[i][j] > mat[i][j+1]);
                bool top = (i == 0 || mat[i][j] > mat[i-1][j]);
                bool bottom = (i == row - 1 || mat[i][j] > mat[i+1][j]);

                if(left && right && top && bottom){
                    return {i,j};
                }
            }
        }
        return {-1,-1};
    }
};
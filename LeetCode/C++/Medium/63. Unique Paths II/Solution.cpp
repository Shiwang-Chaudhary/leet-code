class Solution {
public:

    int recursion(int row, int col, vector<vector<int>>& obstacleGrid){
        if(row < 0 || col < 0) return 0;
        if(row == 0 && col == 0) return 1;
        int left = 0;
        int top = 0;
        if(obstacleGrid[row][col] != 1){// means no obstacle on the current path
            left = recursion(row, col - 1, obstacleGrid);
            top = recursion(row - 1, col, obstacleGrid);
        }
        return left + top;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row = obstacleGrid.size();
        int col = obstacleGrid[0].size();
        //we must send rowindex and colindex instead of number of rows and cols
        return recursion(row - 1, col - 1, obstacleGrid);
    }
};
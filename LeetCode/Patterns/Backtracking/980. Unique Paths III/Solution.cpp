class Solution {
public:

    int recHelper(int row, int col, int visited, int totalBlocks, vector<vector<int>>& grid){
        if(grid[row][col] == 2){
            if(visited == totalBlocks){
                return 1;
            }else{
                return 0;
            }
        }
        int ans = 0;
        int rs = grid.size();
        int cs = grid[0].size();
        if(row + 1 < rs){
            if(grid[row+1][col] != -1){
                int current = grid[row][col];
                grid[row][col] = -1;
                ans = ans + recHelper(row + 1, col, visited + 1, totalBlocks, grid);
                grid[row][col] = current;
            }
        }
        if(row - 1 >= 0){
            if(grid[row-1][col] != -1){
                int current = grid[row][col];
                grid[row][col] = -1;
                ans = ans + recHelper(row - 1, col, visited + 1, totalBlocks, grid);
                grid[row][col] = current;
            }
        }
        if(col + 1 < cs){
            if(grid[row][col+1] != -1){
                int current = grid[row][col];
                grid[row][col] = -1;
                ans = ans + recHelper(row, col + 1, visited + 1, totalBlocks, grid);
                grid[row][col] = current;
            }
        }
        if(col - 1 >= 0){
            if(grid[row][col-1] != -1){
                int current = grid[row][col];
                grid[row][col] = -1;
                ans = ans + recHelper(row, col - 1, visited + 1, totalBlocks, grid);
                grid[row][col] = current;
            }
        }
        return ans;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        //row,col
        pair<int,int> start = {0,0};
        int rs = grid.size();
        int cs = grid[0].size();
        int totalBlocks = rs * cs;
        for(int row = 0; row < rs; row++){
            for(int col = 0; col < cs; col++){
                if(grid[row][col] == 1){
                    start.first = row;
                    start.second = col;
                }
                if(grid[row][col] == -1){
                    totalBlocks--;
                }
            }
        }
        //mark the starting point as visited:
        int current = grid[start.first][start.second];
        grid[start.first][start.second] = -1;
        int ans = recHelper(start.first, start.second, 1, totalBlocks, grid);
        grid[start.first][start.second] = current;
        return ans;
    }
};
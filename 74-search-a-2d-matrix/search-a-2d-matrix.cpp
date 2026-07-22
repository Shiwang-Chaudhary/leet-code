class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //Brute force: O(n*m) and SC: O(1)
        // int row = matrix.size();
        // int col = matrix[0].size();
        // bool ans = false;
        // for(int i = 0; i < row; i++){
        //     for(int j = 0; j < col; j++){
        //         if(matrix[i][j] == target){
        //             return true;
        //         }
        //     }
        // }
        // return false;

        //Better solution: TC: O(nlog(m)) and SC: O(1)
        int row = matrix.size();
        int col = matrix[0].size();
        for(int i = 0; i < row; i++) {
            int low = 0;
            int high = col - 1;
            while(low <= high) {
                int mid = low + (high - low) / 2;
                if(matrix[i][mid] == target)
                    return true;
                if(matrix[i][mid] < target)
                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }
        return false;

        //Optimal solution: TC: O(log(row*col)) and SC: O(1)
        // int row = matrix.size();
        // int col = matrix[0].size();
        // int low = 0;
        // int high = row * col-1; //total index of new virtual array.
        // while(low <= high){
        //     int mid = low + (high - low)/2;
        //     int rowIndex = mid/col;
        //     int colIndex = mid % col;
        //     if(matrix[rowIndex][colIndex] == target){
        //         return true;
        //     }else if(matrix[rowIndex][colIndex] < target){
        //         low = mid + 1;
        //     }else{
        //         high = mid - 1;
        //     }
        // }
        // return false;
    }
};
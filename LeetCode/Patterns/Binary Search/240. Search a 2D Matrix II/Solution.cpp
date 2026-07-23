class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // //Brute force: TC: O(n^2) and SC: O(1)
        // int row = matrix.size();
        // int col = matrix[0].size();
        // for(int i = 0; i < row; i++){
            
        //     for(int j = 0; j < col; j++){
        //         if(matrix[i][j] == target){
        //             return true;
        //         }
        //     }
        // }
        // return false;

        int row = matrix.size();
        int col = matrix[0].size();
        for(int i = 0; i < row; i++){
            int low = 0, high = col-1;
            while(low <= high){
                int mid = low + (high - low)/2;
                if(matrix[i][mid] == target){
                    return true;
                }else if(matrix[i][mid] < target){
                    low = mid + 1;
                }else{
                    high = mid - 1;
                }
            }
        }
        return false;
    }
};
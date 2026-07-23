class Solution {
public:

    int maxElementCol(vector<vector<int>>& mat, int col){
        int n = mat.size();
        int ans = INT_MIN;
        int index = -1;
        for(int i = 0; i < n; i++){
            if(ans < mat[i][col]){
                ans = mat[i][col];
                index = i;
            }
        }
        return index;
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        //Brute force: TC: O(n*m) and SC: O(1)
        // int row = mat.size();
        // int col = mat[0].size();
        // for(int i = 0; i < row; i++){
        //     for(int j = 0; j < col; j++){
        //         if nothing exist on element left that means -1 exist and element is always greater than -1 so j == 0 always satisfies, same goes for other condition as well, try chatgpt if not cleared.
        //         bool left = (j == 0 || mat[i][j] > mat[i][j-1]);
        //         bool right = (j == col - 1 || mat[i][j] > mat[i][j+1]);
        //         bool top = (i == 0 || mat[i][j] > mat[i-1][j]);
        //         bool bottom = (i == row - 1 || mat[i][j] > mat[i+1][j]);

        //         if(left && right && top && bottom){
        //             return {i,j};
        //         }
        //     }
        // }
        // return {-1,-1};

//sdsad
        //Binary search: TC: O(row*log(col)) and SCL O(1)
        int row = mat.size();
        int col = mat[0].size();
        //We are doing binary search on col, we can do for either on column or row
        int low = 0;
        int high = col-1;
        while(low <= high){
            int mid = low + (high - low)/2;
            int rowindex = maxElementCol(mat, mid);
            int left = mid-1 >= 0 ? mat[rowindex][mid-1] : -1;
            int right = mid + 1 < col ? mat[rowindex][mid+1] : -1;
            if(mat[rowindex][mid] > left && mat[rowindex][mid] > right){
                return {rowindex, mid};
            }else if(mat[rowindex][mid] < left){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return {-1,-1};
    }
};
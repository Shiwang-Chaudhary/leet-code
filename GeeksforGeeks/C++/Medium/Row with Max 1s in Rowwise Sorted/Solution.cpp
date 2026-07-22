class Solution {
  public:
    int rowWithMax1s(vector<vector<int>> &mat) {
        // Brute solution: TS: O(n*m) and SC: O(1)
        // int row = mat.size();
        // int col = mat[0].size();
        // int maxOnes = -1;
        // int index = -1;
        // for(int i = 0; i < row; i++){
        //     int count = -1;
        //     for(int j = 0; j < col; j++){
        //         if(mat[i][j] == 1){
        //             count++;
        //         }
        //     }
        //     if(maxOnes < count){
        //         maxOnes = count;
        //         index = i;
        //     }
        // }
        // return index;
        int row = mat.size();
        int col = mat[0].size();
        int index = -1;
        int maxOnes = -1;
        for(int i = 0; i < row; i++){
            int low = 0;
            int high = col-1;
            int count = -1;
            while(low <= high){
                int mid = low + (high - low)/2;
                if(mat[i][mid] == 1){
                    count = col - mid;
                    high = mid - 1;
                }else{
                    low = mid + 1;
                }
            }
            if(maxOnes < count){
                maxOnes = count;
                index = i;
            }
        }
        return index;
    }
};
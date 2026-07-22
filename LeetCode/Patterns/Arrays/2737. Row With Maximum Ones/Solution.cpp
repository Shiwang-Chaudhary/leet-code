class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        //Optimal solution: TS: O(n*m) and SC: O(1)
        int row = mat.size();
        int col = mat[0].size();
        int maxOnes = -1;
        int index = -1;
        for(int i = 0; i < row; i++){
            int count = 0;
            for(int j = 0; j < col; j++){
                if(mat[i][j] == 1){
                    count++;
                }
            }
            if(maxOnes < count){
                maxOnes = count;
                index = i;
            }
        }
        return {index, maxOnes};

    }
};
class Solution {
public:

    int recursion(int rowInd, int colInd){
        if(rowInd < 0) return 0;
        if(colInd < 0) return 0;
        if(colInd == 0 && rowInd == 0) return 1;
        // going left
        int left = recursion(rowInd, colInd - 1);
        int top = recursion(rowInd - 1, colInd);
        return left + top;
    }
        
    //Taking path from m-1, n-1 to 0,0 basically doing the opposite and we can only move either left or top
    int uniquePaths(int m, int n) {
        return recursion(m-1, n-1);
    }
};
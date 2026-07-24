class Solution {
  public:
    
    //Count element less than a certain number, we can use upper bound for it
    //instead of using stl upper bound, lets write it ourselves,
    //its main condition is: nums[i]<=elementwearesearching
    
    int upper_bound(vector<int>&nums, int target){
        int low = 0;
        int high = nums.size() - 1;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(nums[mid] <= target){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        return low;
        //Basically it will return the index where the target element should be
        //if target isnt present or it will return the index just next to the target
        //value, in this way we get to know how many elements are in the nums that 
        // are less than target
        //Example: nums = [1,2,3,4,5,6,7], target is 6
        // then ans = 6 because target is present in array so it will return next array
        //Example: nums = [1,2,3,4,5,8], target is 6
        // then ans = 5 because it 6 should be on 5th index
    }
  
    int median(vector<vector<int>> &mat) {
        // vector<int> ans;
        // int row = mat.size();
        // int col = mat[0].size();
        // for(int i = 0; i < row; i++){
        //     for(int j = 0; j < col; j++){
        //         ans.push_back(mat[i][j]);
        //     }
        // }
        // sort(ans.begin(), ans.end());
        // int size = ans.size();
        // if(size % 2 == 0){
        //     int mid = size/2;
        //     return (ans[mid-1]+ans[mid])/2;
        // }
        // return ans[size/2];
        
        int row = mat.size();
        int col = mat[0].size();
        int left = (row*col)/2;
        int maxElement = INT_MIN;
        int minElement = INT_MAX;
        for(int i = 0; i < row; i++){
            maxElement = max(maxElement, mat[i][col-1]);
        }
        for(int i = 0; i < row; i++){
            minElement = min(minElement, mat[i][0]);
        }
        
        int low = minElement;
        int high = maxElement;
        while(low <= high){
            int elementsLessThanMid = 0;
            int mid = low + (high - low)/2;
            for(int i = 0; i < row; i++){
                elementsLessThanMid = elementsLessThanMid + upper_bound(mat[i], mid);
            }
            if(elementsLessThanMid > left){
                //Because we want the most left element that satisfies this condition
                high = mid - 1;
            }else{
                //need more elements
                low = mid + 1;
            }
        }
        return low;
    }
};

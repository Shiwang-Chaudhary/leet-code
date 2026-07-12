class Solution {
public:

    int magnetplacedfunc(vector<int>& nums, int i){
        int n = nums.size();
        int lastplaced = 0;
        int magnetplaced = 1;
        for(int j = 1; j < n; j++){
            if(nums[j] - nums[lastplaced] >= i){
                magnetplaced++;
                lastplaced = j;
            }
        }
        return magnetplaced;
    }

    int maxDistance(vector<int>& position, int k) {
        //Same as cow problem in stiver TUF:
        //Brute force:
        // sort(position.begin(), position.end());
        // int n = position.size();
        // int d = position[n-1] - position[0];
        // for(int i = d; i > 0; i--){
        //     int lastplaced = 0;
        //     int magnetplaced = 1;
        //     for(int j = 1; j < n; j++){
        //         if(position[j] - position[lastplaced] >= i){
        //             magnetplaced++;
        //             lastplaced = j;
        //         }
        //     }
        //     if(magnetplaced >= k) return i;
        // }       
        // return -1; 

        int n = position.size();
        int ans = -1;
        sort(position.begin(), position.end());
        int diff = position[n-1] - position[0];
        int low = 1;
        int high = diff;
        while(low <= high){
            int mid = low + (high - low)/2;
            int magnetplaced = magnetplacedfunc(position, mid);
            if(magnetplaced >= k){
                ans = mid;
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        return ans;
    }
};
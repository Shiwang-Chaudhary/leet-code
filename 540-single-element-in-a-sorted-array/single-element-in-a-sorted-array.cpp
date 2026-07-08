class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        //Brute solution: TC: O(n^2) and SC: O(1)
        // int n = nums.size();
        // for(int i = 0; i < n; i++){
        //     int count = 0;
        //     //j must start from 0 otherwise it will skip the prvious repeated elements.
        //     for(int j = 0; j < n; j++){
        //         if(nums[i] == nums[j]){
        //             count++;
        //         }
        //     }
        //     if(count == 1){
        //         return nums[i];
        //     }
        // }
        // return -1;

        //Better solution: TC: O(n) and SC: O(n)
        // int n = nums.size();
        // unordered_map<int, int>mp;
        // for(int i = 0; i < n; i++){
        //     mp[nums[i]]++;
        // }
        // for(auto it: mp){
        //     if(it.second == 1){
        //         return it.first;
        //     }
        // }
        // return -1;

        //Optimal solution:
        int n = nums.size();
        //if only single element is present.
        if(n == 1) return nums[0];
        //if 1st element is not equal to 2nd element that means 1st element is the unique element:
        if(nums[0] != nums[1]) return nums[0];
        //if last element is the unique element:
        if(nums[n-1] != nums[n-2]) return nums[n-1];
        
        //since we already check for first and last element.
        int low = 1;
        int high = n-2;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(nums[mid] != nums[mid+1] && nums[mid] != nums[mid-1]){ 
                return nums[mid];
            }
            //when mid is even:
            if(mid % 2 == 0){
                //element is after mid
                if(nums[mid] == nums[mid+1]){
                    low = mid + 1;
                }else{
                    //element is before mid
                    high = mid - 1;
                }
            }else{
                //when mid is odd:
                //element is after mid
                if(nums[mid] == nums[mid-1]){
                    low = mid + 1;
                }else{
                    //element is somewhere before mid
                    high = mid - 1;
                }
            }
        }
        return -1;
    }
};
class Solution {
public:

    int recHelper(int index, int minimum, int sum, vector<int>& nums){
        if(index == nums.size()) return 0;
        minimum = min(minimum, nums[index]);
        return minimum + recHelper(index + 1, minimum, sum, nums);
    }

    int sumSubarrayMins(vector<int>& arr) {
        int sum = 0;
        for(int i = 0; i < arr.size(); i++){
            sum = sum + recHelper(i, arr[i], sum, arr);
        }
        return sum;
    }
};
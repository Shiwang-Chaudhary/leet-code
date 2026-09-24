class Solution {
public:

    int recHelper(int index, int minimum, vector<int>& nums){
        if(index == nums.size()) return 0;
        minimum = min(minimum, nums[index]);
        return minimum + recHelper(index + 1, minimum, sum, nums);
    }

    int sumSubarrayMins(vector<int>& arr) {
        long long sum = 0;
        for(int i = 0; i < arr.size(); i++) {
            sum += recHelper(i, arr[i], arr);
        }
        return sum % (1000000007);
    }
};
class Solution {
public:

    int recHelper(int index, int minimum, vector<int>& nums){
        if(index == nums.size()) return 0;
        minimum = min(minimum, nums[index]);
        return minimum + recHelper(index + 1, minimum, nums);
    }

    int sumSubarrayMins(vector<int>& arr) {
        //Brute force: TC: O(n^2) and SC: O(n)(recursion stack)
        // long long sum = 0;
        // for(int i = 0; i < arr.size(); i++) {
        //     sum += recHelper(i, arr[i], arr);
        // }
        // return sum % (1000000007);

        //Brute force 2: TC: O(n^2) and SC: O(1)
        long long sum = 0;
        for(int i = 0; i < arr.size(); i++){
            int m = arr[i]; //minimum
            for(int j = i; j < arr.size(); j++){
                m = min(arr[j], m);
                sum = sum + m;
            }
        }
        return sum % (1000000007);
    }
};
class Solution {
public:

    void recHelper(int index, int sum, int n, int k, vector<int>& temp, vector<vector<int>>& ans, vector<int>& nums){
        if(sum == n && temp.size() == k){
            ans.push_back(temp);
            return;
        }
        if(sum > n) return;
        if(index == nums.size()) return;
        if(temp.size() > k) return;
        int element = nums[index];
        sum = sum + element;
        temp.push_back(element);
        recHelper(index + 1, sum, n, k, temp, ans, nums);
        sum = sum - element;
        temp.pop_back();
        recHelper(index + 1, sum, n, k, temp, ans, nums);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums = {1,2,3,4,5,6,7,8,9};
        vector<int> temp;
        vector<vector<int>> ans;
        recHelper(0, 0, n, k, temp, ans, nums);
        return ans;
    }
};
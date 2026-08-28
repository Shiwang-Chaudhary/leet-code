class Solution {
public:

    void recHelper(int index, int target, int sum, vector<int>& nums,vector<vector<int>>& ans, vector<int>& temp){
        if(sum == target){
            ans.push_back(temp);
            return;
        }
        if(sum > target) return;
        if(index == nums.size()) return;

        int element = nums[index];
        sum = sum + element;
        temp.push_back(element);
        recHelper(index, target, sum, nums, ans, temp);
        //after using repeated element:
        sum = sum - element;
        temp.pop_back();
        index++;
        recHelper(index, target, sum, nums, ans, temp);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        recHelper(0, target, 0, candidates, ans, temp);
        return ans;
    }
};
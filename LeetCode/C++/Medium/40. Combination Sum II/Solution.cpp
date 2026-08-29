class Solution {
public:

    void recHelper(int index, int sum, int target, vector<int>& nums, vector<vector<int>>& ans, vector<int>& temp){
        if(sum == target){
            ans.push_back(temp);
            return;
        }
        if(index == nums.size()){
            return;
        }
        if(sum > target) return;
        int element = nums[index];
        sum = sum + element;
        temp.push_back(element);
        recHelper(index + 1, sum, target, nums, ans, temp);
        sum = sum - element;
        temp.pop_back();
        while(index + 1 < nums.size() && nums[index] == nums[index+1]){
            index++;
        }
        recHelper(index + 1, sum, target, nums, ans, temp);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> temp;
        recHelper(0, 0, target, candidates, ans, temp);
        return ans;
    }
};
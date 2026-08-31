class Solution {
public:

    void recHelper(int index, vector<int>& temp, vector<int>& nums, vector<vector<int>>& ans){
        if(index == nums.size()){
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[index]);
        recHelper(index + 1, temp, nums, ans);
        temp.pop_back();
        while(index + 1 < nums.size() && nums[index] == nums[index + 1]) index++;
        recHelper(index + 1, temp, nums, ans);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        //Optimal solution: TC: O(n × 2^n) SC: O(n) auxiliary space and O(n × 2^n) including output because ans can contains upto 2^n elements...
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> temp;
        recHelper(0, temp, nums, ans);
        return ans;
    }
};
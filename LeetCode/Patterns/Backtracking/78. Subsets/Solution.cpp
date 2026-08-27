class Solution {
public:

    void recHelper(int index, vector<vector<int>>& ans,vector<int>& temp, vector<int>& nums){
        if(index == nums.size()){
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[index]);
        index++;
        recHelper(index, ans, temp, nums);
        temp.pop_back();
        recHelper(index, ans, temp, nums);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        recHelper(0, ans, temp, nums);
        return ans;
    }
};
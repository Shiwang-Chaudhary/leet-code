class Solution {
public:

    void recHelper(int index, int size, vector<vector<int>>& ans,vector<int>& temp, vector<int>& nums){
        if(index == size){
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[index]);
        index++;
        recHelper(index, size, ans, temp, nums);
        temp.pop_back();
        recHelper(index, size, ans, temp, nums);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        int size = nums.size();
        int index = 0;
        vector<vector<int>> ans;
        vector<int> temp;
        recHelper(index, size, ans, temp, nums);
        return ans;
    }
};
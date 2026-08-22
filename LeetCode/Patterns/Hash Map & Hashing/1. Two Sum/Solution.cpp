class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int,int> mp;
        for(int i=0; i<n; i++){
            int rem = target-nums[i];
            auto it = mp.find(rem);
            if(it!=mp.end()){
                return {it->second,i};
            }
            mp[nums[i]] = i;
            
        }
        return {};
    }
};
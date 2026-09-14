class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        //Brute force: TC: O(n) and SCL O(n)
        // unordered_map<int,int> mp;
        // vector<int> ans;
        // for(int i = 0; i < nums.size(); i++){
        //     mp[nums[i]]++;
        // }
        // for(auto it: mp){
        //     if(it.second == 1){
        //         ans.push_back(it.first);
        //     }
        // }
        // return ans;

        //Optimal solution: TC:O(2n) and SC: O(1)
        long long XOR = 0;
        int el1 = 0;
        int el2 = 0;
        for(int i = 0; i < nums.size(); i++){
            XOR ^= nums[i];
        }
        long long rightMostBit = (XOR & (XOR-1)) ^ XOR;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] & rightMostBit){
                //if rightmost bit is of nums[i] is set then it will go to element 1 otherwise element 2
                el1 ^= nums[i];
            }else{
                el2 ^= nums[i];
            }
        }
        return {el1, el2};
    }
};
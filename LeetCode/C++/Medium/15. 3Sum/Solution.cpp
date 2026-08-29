class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //Better solution: TC: O(n^2 logn) and SC: O(n)
        // int n = nums.size();
        // //For storing Unique elements.
        // set<vector<int>> ans;
        
        // for(int i = 0; i<n; i++){
        //     //For storing unique element that arent in set but can be third element:
        //     unordered_set<int> hashset;
        //     for(int j = i+1; j<n; j++){
        //         int third = -(nums[i]+nums[j]);
        //         if(hashset.find(third)!=hashset.end()){
        //             vector<int> temp = {nums[i], nums[j], third};
        //             //Sort this vector so that set can check whether this vector is already available or not to avoid adding duplicate vectors:
        //             sort(temp.begin(),temp.end());
        //             ans.insert(temp);
        //         }
        //         hashset.insert(nums[j]);
        //     }
        // }
        // vector<vector<int>> result(ans.begin(), ans.end());
        // return result;


        //Optimal solution: Two pointers approach,
        //TC: O(n^2) and SC: O(1) answer space doesnt count.
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(int i = 0; i<n; i++){
            //if previous and current element is same then skip current iteration and moves to next.
            if(i>0 and nums[i]==nums[i-1]) continue;
            //We have to run the loop until j and k crosses each other
            int j = i+1;
            int k = n-1;
            while(j<k){
                int sum = nums[i]+nums[j]+nums[k];
                if(sum>0){
                    k--;
                }else if(sum<0){
                    j++;
                }else{
                    //when sum == 0
                    ans.push_back({nums[i],nums[j],nums[k]});
                    //We did j++ and k-- to change the element.
                    j++;
                    k--;
                    //Next element might be same, so we do this,
                    //Watch striver video if not understood.
                    while(j<k && nums[j]==nums[j-1]) j++;
                    while(j<k && nums[k]==nums[k+1]) k--;
                }
            }
        }
        return ans;
    }
};
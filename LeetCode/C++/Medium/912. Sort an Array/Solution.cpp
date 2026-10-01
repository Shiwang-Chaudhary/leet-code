class Solution {
public:

    int partition(vector<int>& nums, int start, int end){
        //pivot index
        int index = start - 1;
        //pivot element
        int pivElement = nums[end];
        for(int i = start; i <= end; i++){
            if(nums[i] < pivElement){
                index++;
                swap(nums[i], nums[index]);
            }
        }
        index++;
        swap(nums[index], nums[end]);
        return index;
    }

    void qs(vector<int>& nums, int start, int end){
        if(start >= end) return;
        int pivotIndex = partition(nums, start, end);
        //left half where elements are less than pivot
        qs(nums, start, pivotIndex - 1);
        //right half where elements are greater than pivot
        qs(nums, pivotIndex + 1, end);
    }

    vector<int> sortArray(vector<int>& nums) {
        qs(nums, 0, nums.size() - 1);
        return nums;
    }
};
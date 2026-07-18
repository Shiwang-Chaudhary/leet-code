class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        double median = 0;
        nums1.insert(nums1.end(), nums2.begin(), nums2.end());
        sort(nums1.begin(), nums1.end());
        int s = n+m;
        if(s%2 == 0){
            //even
            int middle = s/2;
            median = double (nums1[middle] + nums1[middle-1])/2;
        }else{
            //odd
            int middle = s/2;
            median = nums1[middle];
        }
        return median;
    }
};
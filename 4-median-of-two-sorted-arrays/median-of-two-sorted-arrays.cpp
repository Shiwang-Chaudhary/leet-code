class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        //Brute solution: TC: O((n+m)log(n+m)) and SC: O(1)
        // int n = nums1.size();
        // int m = nums2.size();
        // double median = 0;
        // nums1.insert(nums1.end(), nums2.begin(), nums2.end());
        // sort(nums1.begin(), nums1.end());
        // int s = n+m;
        // if(s%2 == 0){
        //     //even
        //     int middle = s/2;
        //     median = double (nums1[middle] + nums1[middle-1])/2;
        // }else{
        //     //odd
        //     int middle = s/2;
        //     median = nums1[middle];
        // }
        // return median;


        int i = 0;
        int j = 0;
        int n = nums1.size();
        int m = nums2.size();
        vector<int> sorted;
        while(i<n && j<m){
            if(nums1[i] < nums2[j]){
                sorted.push_back(nums1[i]);
                i++;
            }else{
                sorted.push_back(nums2[j]);
                j++;
            }
        }
        while(i<n){
            sorted.push_back(nums1[i]);
            i++;
        }
        while(j<m){
            sorted.push_back(nums2[j]);
            j++;
        }
        int s = n+m;
        double median = 0;
        if(s%2 == 0){
            //even
            int middle = s/2;
            median = (sorted[middle] + sorted[middle-1])/2.0;
        }else{
            //odd
            int middle = s/2;
            median = sorted[middle];
        }
        return median;
    }
};
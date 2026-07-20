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

        //Better solution: TC: O(n+m) and SC: O(n+m) due to extra array
        // int i = 0;
        // int j = 0;
        // int n = nums1.size();
        // int m = nums2.size();
        // vector<int> sorted;
        // while(i<n && j<m){
        //     if(nums1[i] < nums2[j]){
        //         sorted.push_back(nums1[i]);
        //         i++;
        //     }else{
        //         sorted.push_back(nums2[j]);
        //         j++;
        //     }
        // }
        // while(i<n){
        //     sorted.push_back(nums1[i]);
        //     i++;
        // }
        // while(j<m){
        //     sorted.push_back(nums2[j]);
        //     j++;
        // }
        // int s = n+m;
        // double median = 0;
        // if(s%2 == 0){
        //     //even
        //     int middle = s/2;
        //     median = (sorted[middle] + sorted[middle-1])/2.0;
        // }else{
        //     //odd
        //     int middle = s/2;
        //     median = sorted[middle];
        // }
        // return median;

        //Better solution 2: TC: O(n+m) and SC: O(1)
        //Same as better solution but we didnt take extra array but instead take current and previous element since we only need those at mid index of merged sorted array.
        int i = 0;
        int j = 0;
        int n = nums1.size();
        int m = nums2.size();
        int current = 0;
        int prev = 0;
        int count = -1;
        int s = m+n;
        int mid = s/2;
        while(i<n && j<m){
            prev = current;
            if(nums1[i] < nums2[j]){
                current = nums1[i];
                i++;
            }else{
                current = nums2[j];
                j++;
            }
            count ++;
            if(count == mid){
                break;
            }
        }
        while (count < mid && i < n) {
            prev = current;
            current = nums1[i++];
            count++;
        }

        // Process remaining elements of nums2
        while (count < mid && j < m) {
            prev = current;
            current = nums2[j++];
            count++;
        }
        double median = 0;
        if(s%2 == 0){
            //even
            median = (current + prev)/2.0;
        }else{
            //odd
            median = current;
        }
        return median;
        //
    }
};
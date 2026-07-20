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
        // int i = 0;
        // int j = 0;
        // int n = nums1.size();
        // int m = nums2.size();
        // int current = 0;
        // int prev = 0;
        // int count = -1;
        // int s = m+n;
        // int mid = s/2;
        // while(i<n && j<m){
        //     prev = current;
        //     if(nums1[i] < nums2[j]){
        //         current = nums1[i];
        //         i++;
        //     }else{
        //         current = nums2[j];
        //         j++;
        //     }
        //     count ++;
        //     if(count == mid){
        //         break;
        //     }
        // }
        // while (count < mid && i < n) {
        //     prev = current;
        //     current = nums1[i++];
        //     count++;
        // }

        // // Process remaining elements of nums2
        // while (count < mid && j < m) {
        //     prev = current;
        //     current = nums2[j++];
        //     count++;
        // }
        // double median = 0;
        // if(s%2 == 0){
        //     //even
        //     median = (current + prev)/2.0;
        // }else{
        //     //odd
        //     median = current;
        // }
        // return median;

        //Optimal Solution: TC: O(min(log(m+n))) because we are taking shorter array and SC: O(1)
        int n1 = nums1.size();
        int n2 = nums2.size();
        if(n1 > n2) return findMedianSortedArrays(nums2, nums1);
        //We will take the smaller array just for better performance
        //We take low = 0 and high = n1 because we can take 0 element from nums1 or some elements or all the element (n1) from nums1 and remaining from nums2.
        int low = 0, high = n1; //Since n1 is the smallest
        //We use this formula for taking number of elements on left side, its good for even and odd number of elements both.
        int leftSize = (n1+n2+1)/2;
        int totalSize = n1+n2;

        //Binary Search:
        while(low <= high){
            //means we have taken mid1 elements from nums1
            int mid1 = low + (high - low)/2;
            //means we have taken mid2 elements from nums2
            int mid2 = leftSize - mid1;
            int l1 = INT_MIN, l2 = INT_MIN;
            int r1 = INT_MAX, r2 = INT_MAX;
            //we check mid1 < n1 because mid1 can be the total no of elements in the array and that will be out of bound in case of mid1 = n1.
            if(mid1 < n1) r1 = nums1[mid1];
            if(mid2 < n2) r2 = nums2[mid2]; //same as above condition
            //we check mid1-1 >= 0 because we have to take (mid1-1)th element and if mid1 is the first element(0th) then mid1 - 1 will be -1 and that is out of bound.
            if(mid1 - 1 >= 0) l1 = nums1[mid1-1];
            if(mid2 - 1 >= 0) l2 = nums2[mid2-1]; //same as above condition

            // Correct partition:
            // Every element on the left partition is <= every element on the right partition.
            // Since each array is already sorted, we only need to check:
            // l1 <= r2 and l2 <= r1.
            if(l1 <= r2 && l2 <= r1){
                if(totalSize % 2 == 0){
                    //Even number of elements:
                    //we are returning them because we want maximum from left and minimum from right: EXAMPLE: 1 2 3 3 4 | 6 7 10 12 15, so left maximum is 4 and right minimum is 6 and this is median = (4 + 6)/2
                    return ((double)(max(l1,l2) + min(r1,r2)))/2.0;
                }else{
                    //Odd number of total elements:
                    return max(l1, l2);
                }
            //means give less element from shorter array    
            }else if(l1 > r2) high = mid1 - 1;
            //means give more element from shorter array
            else low = mid1 + 1;
        }////asasas
        return 0;
    }
};
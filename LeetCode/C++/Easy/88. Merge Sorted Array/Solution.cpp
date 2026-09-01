class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        //TC: O(m+n) and SC: O(m+n)
        // vector<int> ans;
        // int i = 0;
        // int j = 0;
        // while(i<m && j<n){
        //     if(nums1[i]<nums2[j]){
        //         ans.push_back(nums1[i]);
        //         i++;
        //     }else{
        //         ans.push_back(nums2[j]);
        //         j++;
        //     }
        // }
        // while(i<m){
        //     ans.push_back(nums1[i]);
        //     i++;
        // }
        // while(j<n){
        //     ans.push_back(nums2[j]);
        //     j++;
        // }
        // nums1 = ans;
        
        //Better solution:
        //Time Complexity: O(m log m + n log n)
        // Space Complexity: O(1)
        // nums1.resize(m);//Remove extra zeros;
        // int i = m-1;
        // int j = 0;
        // while(i>=0 && j<n){
        //     if(nums1[i] > nums2[j]){
        //         swap(nums1[i], nums2[j]);
        //         i--;
        //         j++;
        //     }else{
        //         //because all the element in arr1 on left and right on arr2 will be sorted.
        //         break;
        //     }
        // }
        // sort(nums1.begin(), nums1.end());
        // sort(nums2.begin(), nums2.end());
        // nums1.insert(nums1.end(), nums2.begin(), nums2.end());

        //Three pointers approach:  optimal solution: TC: O(m+n)
        //From chatgpt:
        int i = m-1;
        int j = n-1;
        int k = m+n-1;
        while(i>=0 && j>=0){
            if(nums1[i]>nums2[j]){
                nums1[k] = nums1[i];
                i--;
            }else{
                nums1[k] = nums2[j];
                j--;
            }
            k--;
        }
        while(j>=0){
            nums1[k] = nums2[j];
            j--;
            k--;
        }
    }
};
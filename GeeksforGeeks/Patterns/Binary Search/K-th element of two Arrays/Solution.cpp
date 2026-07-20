class Solution {
  public:
    int kthElement(vector<int> &a, vector<int> &b, int k) {
        
        //Better solution 1: TC: O(m+n) and SC: O(m+n)
        // vector<int> sorted;
        // int n = a.size();
        // int m = b.size();
        // int i = 0, j = 0;
        // while(i < n && j < m){
        //     if(a[i] < b[j]){
        //         sorted.push_back(a[i]);
        //         i++;
        //     }else{
        //         sorted.push_back(b[j]);
        //         j++;
        //     }
        // }
        // while(i < n){
        //     sorted.push_back(a[i]);
        //     i++;
        // }
        // while(j < m){
        //     sorted.push_back(b[j]);
        //     j++;
        // }
        // return sorted[k-1];
        
        //Better solution 2: TC: O(n+m) and SC: O(1)
        // int n = a.size();
        // int m = b.size();
        // int current = 0;
        // int count = 0;
        // int i = 0;
        // int j = 0;
        
        // while(i < n && j < m){
        //     if(a[i] < b[j]){
        //         current = a[i];
        //         i++;
        //     }else{
        //         current = b[j];
        //         j++;
        //     }
        //     count++;
        //     if(count == k){
        //         return current;
        //     }
        // }
        // while(i < n){
        //     current = a[i];
        //     i++;
        //     count++;
        //     if(count == k) return current;
        // }
        // while(j < m){
        //     current = b[j];
        //     j++;
        //     count++;
        //     if(count == k) return current;
        // }
        // return 0;
        
        //Optimal solution: Binary search: 
        int n1 = a.size();
        int n2 = b.size();
        if(n1>n2) return kthElement(b,a,k);
        int left = k; //means k element should be on left side 
        //that means the kth element in the sorted array would be the largest element on the left, basically max(l1,l2)
        int totalSize = n1+n2;
        int low = max(0, k-n2); //n2 is larger array and n1 is smaller array size
        int high = min(n1, k); 
        while(low <= high){
            //elements taken from smaller array for left side
            int mid1 = low + (high - low)/2;
            //elements taken from larger array for left side
            int mid2 = left - mid1;
            //We need l1 and l2 for answer and binary search shifting
            int l1 = INT_MIN, l2 = INT_MIN;
            //We need r1 and r2 for binary search shifiting only
            int r1 = INT_MAX, r2 = INT_MAX;
            //Condition to check mid1 and mid2 arnt out of bound
            if (mid1 < n1) r1 = a[mid1];
            if (mid2 < n2) r2 = b[mid2];     
            if(mid1 - 1 >= 0) l1 = a[mid1 - 1];
            if(mid2 - 1 >= 0) l2 = b[mid2 - 1];
            //If the partition is correct:
            if(l1 <= r2 && l2 <= r1){
                return max(l1,l2);
            }else if(l1 > r2){
                //move to left
                high = mid1 - 1;
            }else{
                //move to right
                low = mid1 + 1;
            }
        }
        return 0;
    }
};
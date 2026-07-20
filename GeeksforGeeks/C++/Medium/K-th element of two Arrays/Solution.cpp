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
        int n = a.size();
        int m = b.size();
        int current = 0;
        int count = 0;
        int i = 0;
        int j = 0;
        
        while(i < n && j < m){
            if(a[i] < b[j]){
                current = a[i];
                i++;
            }else{
                current = b[j];
                j++;
            }
            count++;
            if(count == k){
                return current;
            }
        }
        while(i < n){
            current = a[i];
            i++;
            count++;
            if(count == k) return current;
        }
        while(j < m){
            current = b[j];
            j++;
            count++;
            if(count == k) return current;
        }
        return 0;
    }
};
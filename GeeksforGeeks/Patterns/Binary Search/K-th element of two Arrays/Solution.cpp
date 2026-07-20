class Solution {
  public:
    int kthElement(vector<int> &a, vector<int> &b, int k) {
        // code here
        vector<int> sorted;
        int n = a.size();
        int m = b.size();
        int i = 0, j = 0;
        while(i < n && j < m){
            if(a[i] < b[j]){
                sorted.push_back(a[i]);
                i++;
            }else{
                sorted.push_back(b[j]);
                j++;
            }
        }
        while(i < n){
            sorted.push_back(a[i]);
            i++;
        }
        while(j < m){
            sorted.push_back(b[j]);
            j++;
        }
        return sorted[k-1];
    }
};
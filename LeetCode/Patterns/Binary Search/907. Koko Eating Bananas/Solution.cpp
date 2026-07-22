class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
       //Brute force: TC: O(n^2) and SC: O(1) 
        // int hour = 0;
        // int maxpile = *max_element(piles.begin(), piles.end());
        // for(int i = 1; i <=maxpile; i++){
        //     hour = 0;
        //     for(auto bananas : piles){
        //         hour += ceil((double)bananas/i);

        //         if(hour > h) break;
        //     }
        //     if(hour <= h) return i;
        // }
        // return -1;

        //Optimal Solution: TC: O(nlog(maxpile)) and SC: O(1).
        int maxpile = *max_element(piles.begin(), piles.end());
        int low = 1;
        int high = maxpile;
        int ans = -1;
        while(low <= high){
            int mid = low + (high - low)/2;
            long long hour = 0;
            //calculating hour to check if  mid can be k or not:
            for(auto bananas : piles){
                // hour += ceil((double)bananas/mid);
                //ceil used for finding ceil value but it takes time so avoid it and instead use:
                hour += (bananas + mid - 1)/mid;
                if(hour > h) break;
            }
            //if hour is less than required h(hours) then mid can be candidate.
            if(hour <= h){
                ans = mid;
                //if mid is candidate then smallest candidate either will be mid or before mid
                high  = mid - 1;
            }else{
                //if mid cant be candidate then its previous element cant be candidate as well that means candidate will be later than mid.
                low = mid + 1;
            }
        }
        return ans;
    }
};
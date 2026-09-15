class Solution {
public:
    //TC of this function: O(√n)
    bool isPrime(int n){
        if(n < 2) return false;
        for(int i = 2; i*i <= n; i++){
            if(n % i == 0) return false;
        }
        return true;
    }

    int countPrimes(int n) {
        //Brute force: TC: O(n√n) and SC: O(1)
        // int count = 0;
        // for(int i = 1; i < n; i++){
        //     if(isPrime(i)) count++;
        // }
        // return count;

        //Optimal solution using Sieve of Eratosthenes: TC: O(nlog(logn)) and SC: O(k) where k is number of prime numbers
        //mark all numbers as prime initially
        if(n == 0 || n == 1) return 0;
        vector<int> isPrime(n, 1);
        isPrime[0] = 0; // 0 is not prime
        isPrime[1] = 0; // 1 is not prime as well
        //we dont actually need to go till n, only till its square root, reason is in excalidraw file
        for(int i = 2; i*i <= n; i++){
            if(isPrime[i]){
                for(int j = i*i; j <= n; j = j + i){
                    //j will be composite numbers because they are multiples of i, so mark them composite
                    isPrime[j] = 0;
                }
            }
        }
        //now all the numbers in isPrime that are marked as 1 are prime.
        int count = 0;
        for(int i = 2; i < isPrime.size(); i++){
            if(isPrime[i] == 1){
                count++;
            }
        }
        return count;
    }
};
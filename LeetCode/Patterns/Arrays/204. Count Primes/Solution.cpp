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

        //Optimal solution using Sieve of Eratosthenes
    }
};
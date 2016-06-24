//  204. Count Primes
//  
//  Description:
//  Count the number of prime numbers less than a non-negative number, n.
//  Credits:Special thanks to @mithmatt for adding this problem and creating all test cases.
//  Let's start with a isPrime function. To determine if a number is prime, we need to check if it is not divisible by
//  any number less than n. The runtime complexity of isPrime function would be O(n) and hence counting the total prime
//  numbers up to n would be O(n2). Could we do better?
//  As we know the number must not be divisible by any number > n / 2, we can immediately cut the total iterations half
//  by dividing only up to n / 2. Could we still do better?
//
//  Tags: Hash Table, Math
//  
//  https://leetcode.com/problems/count-primes/    

#include <iostream>
#include <gtest/gtest.h>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    // Sieve of Eratosthenes
    int countPrimes(int n) {
        if(n <= 2){
            return 0;
        }

        vector<bool> prime(n, true);
        for(int i = 2; i < sqrt(n); i++){
            if(prime[i]) {
                for(int j = i * i; j < n; j += i){
                    prime[j] = false;
                }
            }
        }

        int count = 0;
        for(int i = 2; i < n; i++){
            if(prime[i]){
                count++;
            }
        }


        return count;
    }
};

TEST(leetcode_204_count_primes, Basic)
{
    Solution *solution = new Solution();
    EXPECT_EQ(0, solution->countPrimes(1));
    EXPECT_EQ(0, solution->countPrimes(0));
    EXPECT_EQ(0, solution->countPrimes(2));
    EXPECT_EQ(1, solution->countPrimes(3));
    EXPECT_EQ(2, solution->countPrimes(4));
    EXPECT_EQ(2, solution->countPrimes(5));
    EXPECT_EQ(3, solution->countPrimes(6));
    EXPECT_EQ(4, solution->countPrimes(8));
    EXPECT_EQ(25, solution->countPrimes(100));
    EXPECT_EQ(168, solution->countPrimes(1000));
    EXPECT_EQ(1117, solution->countPrimes(9000));
    EXPECT_EQ(1229, solution->countPrimes(10000));
    EXPECT_EQ(9592, solution->countPrimes(100000));
    EXPECT_EQ(10544, solution->countPrimes(111111));
    EXPECT_EQ(78498, solution->countPrimes(999999));
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

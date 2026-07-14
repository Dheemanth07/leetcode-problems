// Last updated: 7/14/2026, 3:12:29 PM
1class Solution {
2public:
3    int countPrimes(int n) {
4        // There are no primes less than 2
5        if (n <= 2) {
6            return 0;
7        }
8
9        // Step 1: Create a boolean vector of size n, initialized to true.
10        // std::vector<bool> is highly optimized for space in C++.
11        vector<bool> isPrime(n, true);
12
13        // 0 and 1 are not primes
14        isPrime[0] = false;
15        isPrime[1] = false;
16
17        // Step 2 & 5: Outer loop only needs to go up to the square root of n.
18        // We write p * p < n to avoid the overhead of calling sqrt(n).
19        for (int p = 2; p * p < n; p++) {
20
21            // If p is still marked true, it is prime
22            if (isPrime[p]) {
23
24                // Step 3: Mark all multiples of p as false.
25                // We start at p * p because smaller multiples were crossed out
26                // by smaller primes.
27                for (int i = p * p; i < n; i += p) {
28                    isPrime[i] = false;
29                }
30            }
31        }
32
33        // Step 6: Count the remaining true values
34        int primeCount = 0;
35        for (int p = 2; p < n; p++) {
36            if (isPrime[p]) {
37                primeCount++;
38            }
39        }
40
41        return primeCount;
42    }
43};
// Last updated: 1/24/2026, 4:37:29 PM
1class Solution {
2public:
3    int solve(int n, int k){
4        if(n==1)
5            return 0;
6        return (solve(n-1,k)+k)%n;
7    }
8
9    int findTheWinner(int n, int k) {
10        int winner = solve(n,k)+1;
11        return winner;
12    }
13};
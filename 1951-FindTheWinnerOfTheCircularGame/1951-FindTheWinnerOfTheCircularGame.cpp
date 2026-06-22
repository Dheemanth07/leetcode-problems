// Last updated: 6/22/2026, 6:29:36 PM
class Solution {
public:
    int solve(int n, int k){
        if(n==1)
            return 0;
        return (solve(n-1,k)+k)%n;
    }

    int findTheWinner(int n, int k) {
        int winner = solve(n,k)+1;
        return winner;
    }
};
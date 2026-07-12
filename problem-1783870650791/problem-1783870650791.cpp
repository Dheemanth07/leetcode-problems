// Last updated: 7/12/2026, 9:07:30 PM
1class Solution {
2public:
3    int reverse(int x) {
4        int ans = 0;
5
6        while (x != 0) {
7            int digit = x % 10;
8
9            if (ans > INT_MAX / 10 || (ans == INT_MAX / 10 && digit > 7))
10                return 0;
11
12            if (ans < INT_MIN / 10 || (ans == INT_MIN / 10 && digit < -8))
13                return 0;
14
15            ans = ans * 10 + digit;
16
17            x /= 10;
18        }
19
20        return ans;
21    }
22};
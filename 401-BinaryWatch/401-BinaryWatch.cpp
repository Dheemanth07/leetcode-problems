// Last updated: 1/18/2026, 7:03:36 PM
1class Solution {
2public:
3    vector<string> readBinaryWatch(int n) {
4        vector<string> ans;
5        for (int i = 0; i < 12; i++) {
6            int onBits = setBits(i);
7            if (onBits > n)
8                continue;
9            for (int j = 0; j < 60; j++) {
10                int onBits_j = setBits(j);
11                if (onBits + onBits_j == n) {
12                    string temp = to_string(i) + ":";
13                    if (j < 10) {
14                        temp = temp + "0";
15                    }
16                    temp = temp + to_string(j);
17                    ans.push_back(temp);
18                }
19            }
20        }
21        return ans;
22    }
23    int setBits(int n) {
24        int count = 0;
25        while (n > 0) {
26            n = n & (n - 1);
27            count++;
28        }
29        return count;
30    }
31};
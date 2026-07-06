// Last updated: 7/6/2026, 11:43:35 AM
1class Solution {
2public:
3    bool lemonadeChange(vector<int>& bills) {
4        int fives = 0, tens = 0;
5
6        for (int bill : bills) {
7            switch (bill) {
8            case 5:
9                fives++;
10                break;
11
12            case 10:
13                if (fives == 0)
14                    return false;
15                tens++;
16                fives--;
17                break;
18
19            case 20:
20                if (tens > 0 && fives > 0) {
21                    tens--;
22                    fives--;
23                } else if (fives >= 3)
24                    fives -= 3;
25                else
26                    return false;
27                break;
28            }
29        }
30
31        return true;
32    }
33};
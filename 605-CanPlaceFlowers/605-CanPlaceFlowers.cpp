// Last updated: 7/6/2026, 11:59:56 AM
1class Solution {
2public:
3    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
4        int count = 0;
5
6        for (int i = 0; i < flowerbed.size(); i++) {
7            if (flowerbed[i] == 0) {
8                bool leftEmpty = (!i || !flowerbed[i - 1]);
9                bool rightEmpty =
10                    (i == flowerbed.size() - 1 || !flowerbed[i + 1]);
11
12                if (leftEmpty && rightEmpty) {
13                    flowerbed[i] = 1;
14                    count++;
15                }
16
17                if (count >= n)
18                    return true;
19            }
20        }
21
22        return count >= n;
23    }
24};
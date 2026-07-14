// Last updated: 7/14/2026, 11:31:46 AM
1class Solution {
2public:
3    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
4        unordered_map<int, vector<bool>> map;
5
6        for (vector<int> seats : reservedSeats) {
7            int row = seats[0];
8            int col = seats[1];
9
10            if (map.find(row) == map.end())
11                map[row] = vector<bool>(11, false);
12
13            map[row][col] = true;
14        }
15
16        int maxFam = 2 * n;
17
18        for (auto const& [_, seat] : map) {
19            int leftFree = !(seat[2] || seat[3] || seat[4] || seat[5]);
20            int middleFree = !(seat[4] || seat[5] || seat[6] || seat[7]);
21            int rightFree = !(seat[6] || seat[7] || seat[8] || seat[9]);
22
23            if (leftFree && rightFree)
24                continue;
25            else if (leftFree || rightFree || middleFree)
26                maxFam -= 1;
27            else
28                maxFam -= 2;
29        }
30
31        return maxFam;
32    }
33};
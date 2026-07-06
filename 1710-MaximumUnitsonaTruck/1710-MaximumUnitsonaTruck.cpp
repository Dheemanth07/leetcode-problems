// Last updated: 7/6/2026, 12:57:40 PM
1class Solution {
2public:
3    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
4        int totalUnits = 0;
5
6        sort(boxTypes.begin(), boxTypes.end(),
7             [](const vector<int>& a, const vector<int>& b) {
8                 return a[1] > b[1];
9             });
10
11        for (const auto& box : boxTypes) {
12            int numBoxes = box[0];
13            int unitsPerBox = box[1];
14
15            int boxesToTake = min(numBoxes, truckSize);
16            totalUnits += boxesToTake * unitsPerBox;
17
18            truckSize -= boxesToTake;
19
20            if (!truckSize)
21                break;
22        }
23
24        return totalUnits;
25    }
26};
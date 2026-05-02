// Last updated: 5/2/2026, 7:56:46 PM
1class Solution {
2public:
3    int daysNeeded(vector<int>& weights, int capacity) {
4        int days = 1, load = 0;
5        for (int w : weights) {
6            if (load + w > capacity) {
7                days++;
8                load = w;
9            } else
10                load += w;
11        }
12        return days;
13    }
14
15    int shipWithinDays(vector<int>& weights, int days) {
16        int low = *max_element(weights.begin(), weights.end());
17        int high = accumulate(weights.begin(), weights.end(), 0);
18
19        while (low < high) {
20            int mid = low + (high - low) / 2;
21
22            if (daysNeeded(weights, mid) <= days)
23                high = mid;
24            else
25                low = mid + 1;
26        }
27        return low;
28    }
29};
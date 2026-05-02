// Last updated: 5/2/2026, 7:16:42 PM
1class Solution {
2public:
3    int minEatingSpeed(vector<int>& piles, int h) {
4        // Pillar 1: The Search Space
5        int left = 1;
6
7        // Find the maximum pile to set our upper bound
8        int right = 0;
9        for (int p : piles) {
10            right = std::max(right, p);
11        }
12
13        int best_speed = right; // Store the best valid answer we find
14
15        while (left <= right) {
16            int mid = left + (right - left) / 2;
17
18            // Pillar 2: The Test
19            long long total_hours = 0;
20            for (int p : piles) {
21                // Integer math trick for Ceiling Division: ceil(a/b) = (a + b -
22                // 1) / b
23                total_hours += (p + mid - 1) / mid;
24            }
25
26            // Pillar 3: The Decision
27            if (total_hours <= h) {
28                // Fast enough! Record it, but try to find a slower valid speed
29                best_speed = mid;
30                right = mid - 1;
31            } else {
32                // Too slow! We must eat faster
33                left = mid + 1;
34            }
35        }
36
37        return best_speed;
38    }
39};
40
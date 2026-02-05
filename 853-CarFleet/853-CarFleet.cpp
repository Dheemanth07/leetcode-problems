// Last updated: 2/5/2026, 6:24:09 PM
1class Solution {
2public:
3    int carFleet(int target, vector<int>& position, vector<int>& speed) {
4        int n = position.size();
5        if (n == 0)
6            return 0;
7
8        vector<pair<int, double>> cars(n);
9        for (int i = 0; i < n; i++) {
10            // Time = (Distance remaining) / Speed
11            double time = (double)(target - position[i]) / speed[i];
12            cars[i] = {position[i], time};
13        }
14
15        // Sort by position ascending (0 -> Target)
16        sort(cars.begin(), cars.end());
17
18        stack<double> st;
19
20        // Process from the car closest to target (at the back of the sorted
21        // vector)
22        for (int i = n - 1; i >= 0; i--) {
23            double currentTime = cars[i].second;
24
25            // If stack is empty, this is the first car (closest to target)
26            if (st.empty()) {
27                st.push(currentTime);
28            }
29            // If the current car takes MORE time than the fleet in front of it
30            else if (currentTime > st.top()) {
31                st.push(currentTime);
32            }
33            // If currentTime <= st.top(), the car joins the fleet ahead.
34            // We don't push it because it's not a new fleet leader.
35        }
36
37        // The number of fleet leaders in the stack is the total number of
38        // fleets
39        return st.size();
40    }
41};
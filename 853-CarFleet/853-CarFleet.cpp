// Last updated: 6/27/2026, 12:23:06 PM
1class Solution {
2public:
3    int carFleet(int target, vector<int>& position, vector<int>& speed) {
4        int n = position.size();
5
6        vector<pair<int, double>> cars(n);
7
8        for (int i = 0; i < n; i++)
9            cars[i] = {position[i], (double)(target - position[i]) / speed[i]};
10
11        sort(cars.rbegin(), cars.rend());
12
13        int fleetCount = 0;
14        double max = 0.0;
15
16        for (auto& car : cars) {
17            if (car.second > max) {
18                max = car.second;
19                fleetCount++;
20            }
21        }
22
23        return fleetCount;
24    }
25};
26
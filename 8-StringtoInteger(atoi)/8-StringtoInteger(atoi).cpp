// Last updated: 7/22/2026, 8:38:22 PM
1class Solution {
2public:
3    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
4        int total_gas = 0;
5        int total_cost = 0;
6        int start_station = 0;
7        int current_tank = 0;
8
9        for (int i = 0; i < gas.size(); i++) {
10            total_gas += gas[i];
11            total_cost += cost[i];
12
13            current_tank += (gas[i] - cost[i]);
14
15            if (current_tank < 0) {
16                start_station = i + 1;
17                current_tank = 0;
18            }
19
20        }
21        
22        if (total_gas < total_cost)
23            return -1;
24
25        return start_station;
26    }
27};
// Last updated: 7/17/2026, 2:01:40 PM
class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = costs.size() / 2;
        int minCost = 0;

        // nth_element places the top 'n' cheapest-to-divert-to-A people
        // in the first half of the array. It runs in O(N) time.
        nth_element(costs.begin(), costs.begin() + n, costs.end(),
                    [](const vector<int>& a, const vector<int>& b) {
                        // Compare the opportunity cost (Cost A - Cost B)
                        return (a[0] - a[1]) < (b[0] - b[1]);
                    });

        // Sum up the costs. The first half goes to A, second half to B.
        for (int i = 0; i < n; i++) {
            minCost += costs[i][0];     // First half goes to City A
            minCost += costs[i + n][1]; // Second half goes to City B
        }

        return minCost;
    }
};
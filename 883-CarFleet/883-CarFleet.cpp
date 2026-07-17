// Last updated: 7/17/2026, 2:01:58 PM
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();

        vector<pair<int, double>> cars(n);

        for (int i = 0; i < n; i++)
            cars[i] = {position[i], (double)(target - position[i]) / speed[i]};

        sort(cars.rbegin(), cars.rend());

        int fleetCount = 0;
        double max = 0.0;

        for (auto& car : cars) {
            if (car.second > max) {
                max = car.second;
                fleetCount++;
            }
        }

        return fleetCount;
    }
};

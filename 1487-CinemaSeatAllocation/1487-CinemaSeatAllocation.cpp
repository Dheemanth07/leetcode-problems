// Last updated: 7/16/2026, 9:41:53 PM
class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, vector<bool>> map;

        for (vector<int> seats : reservedSeats) {
            int row = seats[0];
            int col = seats[1];

            if (map.find(row) == map.end())
                map[row] = vector<bool>(11, false);

            map[row][col] = true;
        }

        int maxFam = 2 * n;

        for (auto const& [_, seat] : map) {
            int leftFree = !(seat[2] || seat[3] || seat[4] || seat[5]);
            int middleFree = !(seat[4] || seat[5] || seat[6] || seat[7]);
            int rightFree = !(seat[6] || seat[7] || seat[8] || seat[9]);

            if (leftFree && rightFree)
                continue;
            else if (leftFree || rightFree || middleFree)
                maxFam -= 1;
            else
                maxFam -= 2;
        }

        return maxFam;
    }
};
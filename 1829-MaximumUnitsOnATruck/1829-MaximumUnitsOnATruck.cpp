// Last updated: 7/16/2026, 9:41:43 PM
class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int totalUnits = 0;

        sort(boxTypes.begin(), boxTypes.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] > b[1];
             });

        for (const auto& box : boxTypes) {
            int numBoxes = box[0];
            int unitsPerBox = box[1];

            int boxesToTake = min(numBoxes, truckSize);
            totalUnits += boxesToTake * unitsPerBox;

            truckSize -= boxesToTake;

            if (!truckSize)
                break;
        }

        return totalUnits;
    }
};
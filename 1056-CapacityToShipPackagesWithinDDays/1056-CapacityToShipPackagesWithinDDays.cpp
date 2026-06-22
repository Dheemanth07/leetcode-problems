// Last updated: 6/22/2026, 6:30:36 PM
class Solution {
public:
    int daysNeeded(vector<int>& weights, int capacity) {
        int days = 1, load = 0;
        for (int w : weights) {
            if (load + w > capacity) {
                days++;
                load = w;
            } else
                load += w;
        }
        return days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (daysNeeded(weights, mid) <= days)
                high = mid;
            else
                low = mid + 1;
        }
        return low;
    }
};
// Last updated: 7/17/2026, 2:01:56 PM
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // Pillar 1: The Search Space
        int left = 1;

        // Find the maximum pile to set our upper bound
        int right = *max_element(piles.begin(), piles.end());

        int best_speed = right; // Store the best valid answer we find

        while (left <= right) {
            int mid = left + (right - left) / 2;

            // Pillar 2: The Test
            long long total_hours = 0;
            for (int p : piles)
                // Integer math trick for Ceiling Division: ceil(a/b) = (a + b -
                // 1) / b
                total_hours += (p + mid - 1) / mid;

            // Pillar 3: The Decision
            if (total_hours <= h) {
                // Fast enough! Record it, but try to find a slower valid speed
                best_speed = mid;
                right = mid - 1;
            } else
                // Too slow! We must eat faster
                left = mid + 1;
        }

        return best_speed;
    }
};

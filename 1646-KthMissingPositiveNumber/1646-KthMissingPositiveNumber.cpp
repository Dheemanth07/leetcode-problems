// Last updated: 6/22/2026, 6:29:55 PM
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int l = 0, r = arr.size() - 1;
        int res = arr.size() + k;

        // binary Search for index where
        // arr[i] > (i + k)
        while (l <= r) {
            int mid = (l + r) / 2;
            if (arr[mid] > mid + k) {
                res = mid + k;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return res;
    }
};
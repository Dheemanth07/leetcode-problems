// Last updated: 6/22/2026, 7:44:16 PM
1class Solution {
2public:
3    int findKthPositive(vector<int>& arr, int k) {
4        int l = 0, r = arr.size() - 1;
5        int res = arr.size() + k;
6
7        // binary Search for index where
8        // arr[i] > (i + k)
9        while (l <= r) {
10            int mid = (l + r) / 2;
11            if (arr[mid] > mid + k) {
12                res = mid + k;
13                r = mid - 1;
14            } else {
15                l = mid + 1;
16            }
17        }
18
19        return res;
20    }
21};
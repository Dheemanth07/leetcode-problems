// Last updated: 2/8/2026, 10:58:38 AM
1class Solution {
2public:
3    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
4        if (nums1.size() > nums2.size())
5            return findMedianSortedArrays(nums2, nums1);
6        int n1 = nums1.size(), n2 = nums2.size();
7        int l = 0, r = n1;
8        while (l <= r) {
9            int partitionX = l + (r - l) / 2;
10            int partitionY = (n1 + n2 + 1) / 2 - partitionX;
11
12            int maxLeftX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
13            int minRightX = (partitionX == n1) ? INT_MAX : nums1[partitionX];
14            int maxLeftY = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];
15            int minRightY = (partitionY == n2) ? INT_MAX : nums2[partitionY];
16
17            if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
18                if ((n1 + n2) % 2 == 0)
19                    return (max(maxLeftX, maxLeftY) +
20                            min(minRightX, minRightY)) /
21                           2.0;
22                else
23                    return max(maxLeftX, maxLeftY);
24            } else if (maxLeftX > minRightY)
25                r = partitionX - 1;
26            else
27                l = partitionX + 1;
28        }
29        return 0.0;
30    }
31};
32
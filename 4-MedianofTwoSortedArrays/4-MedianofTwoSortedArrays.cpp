// Last updated: 6/24/2026, 6:03:48 PM
1class Solution {
2public:
3    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
4        int n1 = nums1.size(), n2 = nums2.size();
5
6        if (n1 > n2)
7            return findMedianSortedArrays(nums2, nums1);
8
9        int l = 0, r = n1;
10
11        while (l <= r) {
12            int partitionX = l + (r - l) / 2;
13            int partitionY = (n1 + n2 + 1) / 2 - partitionX;
14
15            int maxLeftX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
16            int minRightX = (partitionX == n1) ? INT_MAX : nums1[partitionX];
17            int maxLeftY = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];
18            int minRightY = (partitionY == n2) ? INT_MAX : nums2[partitionY];
19
20            if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
21                if ((n1 + n2) % 2 == 0)
22                    return (max(maxLeftX, maxLeftY) +
23                            min(minRightX, minRightY)) /
24                           2.0;
25                else
26                    return max(maxLeftX, maxLeftY);
27            } else if (maxLeftX > minRightY)
28                r = partitionX - 1;
29            else
30                l = partitionX + 1;
31        }
32
33        return 0.0;
34    }
35};
36
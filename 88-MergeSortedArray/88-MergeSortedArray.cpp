// Last updated: 6/25/2026, 12:53:19 PM
1class Solution {
2public:
3    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
4        int i = m - 1;         // Last element in nums1 (valid part)
5        int j = n - 1;         // Last element in nums2
6        int k = m + n - 1;     // Last position in nums1
7
8        while (i >= 0 && j >= 0) {
9            if (nums1[i] > nums2[j]) 
10                nums1[k--] = nums1[i--];
11            else 
12                nums1[k--] = nums2[j--];
13        }
14
15        // Copy remaining elements from nums2 (if any)
16        while (j >= 0) 
17            nums1[k--] = nums2[j--];
18    }
19};
20
// Last updated: 6/25/2026, 10:43:55 AM
1class Solution {
2public:
3    vector<int> twoSum(vector<int>& numbers, int target) {
4        int n = numbers.size();
5
6        int left = 0, right = n - 1;
7
8        while (left < right) {
9            if ((numbers[left] + numbers[right]) == target)
10                return {left + 1, right + 1};
11            else if ((numbers[left] + numbers[right]) > target)
12                right--;
13            else
14                left++;
15        }
16
17        return {};
18    }
19};
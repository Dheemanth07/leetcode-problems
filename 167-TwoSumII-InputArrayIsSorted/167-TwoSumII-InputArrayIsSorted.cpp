// Last updated: 1/29/2026, 7:06:12 PM
1class Solution {
2public:
3    vector<int> twoSum(vector<int>& numbers, int target) {
4        int n = numbers.size();
5        int left = 0, right = n - 1;
6        while (left < right) {
7            if ((numbers[left] + numbers[right]) == target)
8                return {left + 1, right + 1};
9            else if ((numbers[left] + numbers[right]) > target)
10                right--;
11            else
12                left++;
13        }
14        return {};
15    }
16};
// Last updated: 7/13/2026, 4:23:24 PM
1class Solution {
2public:
3    int numRescueBoats(vector<int>& people, int limit) {
4        int l = 0, r = people.size() - 1;
5        int boats = 0;
6
7        sort(people.begin(), people.end());
8
9        while (l <= r) {
10            if (people[l] + people[r] <= limit)
11                l++;
12            r--;
13            boats++;
14        }
15
16        return boats;
17    }
18};
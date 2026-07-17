// Last updated: 7/17/2026, 2:01:53 PM
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int l = 0, r = people.size() - 1;
        int boats = 0;

        sort(people.begin(), people.end());

        while (l <= r) {
            if (people[l] + people[r] <= limit)
                l++;
            r--;
            boats++;
        }

        return boats;
    }
};
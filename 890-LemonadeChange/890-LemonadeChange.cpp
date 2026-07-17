// Last updated: 7/17/2026, 2:01:57 PM
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fives = 0, tens = 0;

        for (int bill : bills) {
            switch (bill) {
            case 5:
                fives++;
                break;

            case 10:
                if (fives == 0)
                    return false;
                tens++;
                fives--;
                break;

            case 20:
                if (tens > 0 && fives > 0) {
                    tens--;
                    fives--;
                } else if (fives >= 3)
                    fives -= 3;
                else
                    return false;
                break;
            }
        }

        return true;
    }
};
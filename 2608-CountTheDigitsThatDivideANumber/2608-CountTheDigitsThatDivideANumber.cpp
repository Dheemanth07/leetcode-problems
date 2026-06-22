// Last updated: 6/22/2026, 6:29:12 PM
class Solution {
public:
    int countDigits(int num) {
        int count = 0;
        int temp = num;  // Preserve original number

    while (temp > 0) {
        int digit = temp % 10;  // Extract last digit
        if (digit != 0 && num % digit == 0)  // Check divisibility
            count++;
        temp /= 10;  // Remove last digit
    }

    return count;
    }
};
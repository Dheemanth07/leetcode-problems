// Last updated: 4/4/2026, 12:30:39 PM
1class Solution {
2public:
3    bool validPalindrome(string s) {
4        // Lambda function to check if substring from left to right is a
5        // palindrome
6        auto isPalindrome = [&](int left, int right) {
7            // Use two pointers to check characters from both ends
8            while (left < right) {
9                if (s[left] != s[right]) {
10                    return false;
11                }
12                left++;
13                right--;
14            }
15            return true;
16        };
17
18        // Initialize two pointers at the beginning and end of string
19        int left = 0;
20        int right = s.size() - 1;
21
22        // Check characters from both ends moving towards center
23        while (left < right) {
24            // If characters don't match, we have one chance to delete
25            if (s[left] != s[right]) {
26                // Try deleting either the left character or the right character
27                // Check if remaining substring is palindrome after deletion
28                return isPalindrome(left + 1, right) ||
29                       isPalindrome(left, right - 1);
30            }
31            // Move pointers towards center
32            left++;
33            right--;
34        }
35
36        // String is already a palindrome without any deletion
37        return true;
38    }
39};
40
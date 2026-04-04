// Last updated: 4/4/2026, 12:31:56 PM
1class Solution {
2public:
3    bool checkpalindrome(int i, int j, string& s) {
4        // i = 0;
5        // j = s.size() - 1;
6
7        while (i <= j) {
8            if (s[i] != s[j]) {
9                return false;
10            }
11            i++;
12            j--;
13        }
14        return true;
15    }
16    bool validPalindrome(string s) {
17        int i = 0;
18        int j = s.size() - 1;
19        while (i <= j) {
20            if (s[i] == s[j]) {
21                i++;
22                j--;
23            } else {
24                return checkpalindrome(i + 1, j, s) ||
25                       checkpalindrome(i, j - 1, s);
26            }
27        }
28        return true;
29    }
30};
31// class Solution {
32// public:
33//     bool checkpalindrom(int i, int j, string &s) {
34//         while (i <= j) {
35//             if (s[i] != s[j]) {
36//                 return false;
37//             }
38//             i++;
39//             j--;
40//         }
41//         return true;
42//     }
43
44//     bool validPalindrome(string s) {
45//         int i = 0;
46//         int j = s.size() - 1;
47
48//         while (i <= j) {
49//             if (s[i] == s[j]) {
50//                 i++;
51//                 j--;
52//             }
53//             else {
54//                 return checkpalindrom(i + 1, j, s) ||
55//                        checkpalindrom(i, j - 1, s);
56//             }
57//         }
58//         return true;
59//     }
60// };
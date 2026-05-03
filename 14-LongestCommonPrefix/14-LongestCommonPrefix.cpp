// Last updated: 5/3/2026, 11:24:10 AM
1class Solution {
2public:
3    string longestCommonPrefix(vector<string>& strs) {
4        if (strs.empty())
5            return "";
6
7        // Let the first string be our reference guide
8        string reference = strs[0];
9
10        // Pointer 1: Iterate through the columns (characters of reference)
11        for (int i = 0; i < reference.length(); i++) {
12
13            char current_char = reference[i];
14
15            // Pointer 2: Iterate through the rows (every other string in the
16            // array)
17            for (int j = 1; j < strs.size(); j++) {
18
19                // HALT CONDITION 1: The current string is too short to continue
20                // HALT CONDITION 2: We found a mismatched character
21                if (i == strs[j].length() || strs[j][i] != current_char) {
22
23                    // We found the break point!
24                    // Return everything in the reference string up to this
25                    // index.
26                    return reference.substr(0, i);
27                }
28            }
29        }
30
31        // If we make it through the entire reference string without returning,
32        // it means the entire reference string IS the common prefix!
33        return reference;
34    }
35};
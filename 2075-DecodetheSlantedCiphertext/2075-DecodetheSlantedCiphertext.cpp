// Last updated: 4/4/2026, 1:38:13 PM
1class Solution {
2public:
3    string decodeCiphertext(string encodedText, int rows) {
4        int n = encodedText.size();
5        if (n == 0)
6            return "";
7
8        int cols = n / rows;
9        string result;
10
11        // Traverse each diagonal starting from the top row
12        for (int start_col = 0; start_col < cols; ++start_col) {
13            for (int r = 0, c = start_col; r < rows && c < cols; ++r, ++c) {
14                result += encodedText[r * cols + c];
15            }
16        }
17
18        // Remove trailing space padding efficiently
19        while (!result.empty() && result.back() == ' ') {
20            result.pop_back();
21        }
22
23        return result;
24    }
25};
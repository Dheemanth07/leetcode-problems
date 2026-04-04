// Last updated: 4/4/2026, 1:37:17 PM
1class Solution {
2public:
3    string decodeCiphertext(string encodedText, int rows) {
4        int n = encodedText.length();
5        if (n == 0 || rows == 1)
6            return encodedText;
7
8        int cols = n / rows;
9
10        // 1. Initialize the matrix with proper dimensions
11        vector<vector<char>> mat(rows, vector<char>(cols));
12
13        int k = 0;
14        // 2. Fill the matrix sequentially, row by row
15        for (int i = 0; i < rows; i++) {
16            for (int j = 0; j < cols; j++) {
17                mat[i][j] = encodedText[k++];
18            }
19        }
20
21        string decoded = "";
22
23        // 3. Traverse diagonals starting from the top row (i = 0)
24        for (int start_col = 0; start_col < cols; start_col++) {
25            int i = 0;
26            int j = start_col;
27
28            // Move down-right until we hit an edge
29            while (i < rows && j < cols) {
30                decoded += mat[i++][j++];
31            }
32        }
33
34        // 4. Remove trailing padding spaces
35        while (!decoded.empty() && decoded.back() == ' ') {
36            decoded.pop_back();
37        }
38
39        return decoded;
40    }
41};
// Last updated: 4/27/2026, 8:57:21 PM
1class Solution {
2public:
3    vector<int> spiralOrder(vector<vector<int>>& matrix) {
4        int rows = matrix.size();
5        int cols = matrix[0].size();
6
7        int top = 0, bottom = rows - 1;
8        int left = 0, right = cols - 1;
9
10        vector<int> res;
11
12        while (top <= bottom && left <= right) {
13
14            // 1. Left → Right
15            for (int j = left; j <= right; j++)
16                res.push_back(matrix[top][j]);
17            top++;
18
19            // 2. Top → Bottom
20            for (int i = top; i <= bottom; i++)
21                res.push_back(matrix[i][right]);
22            right--;
23
24            // 3. Right → Left
25            if (top <= bottom) {
26                for (int j = right; j >= left; j--)
27                    res.push_back(matrix[bottom][j]);
28                bottom--;
29            }
30
31            // 4. Bottom → Top
32            if (left <= right) {
33                for (int i = bottom; i >= top; i--)
34                    res.push_back(matrix[i][left]);
35                left++;
36            }
37        }
38
39        return res;
40    }
41};
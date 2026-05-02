// Last updated: 5/2/2026, 7:53:07 AM
1class Solution {
2public:
3    vector<vector<int>> generateMatrix(int n) {
4        int top = 0, left = 0;
5        int right = n - 1, bottom = n - 1;
6
7        vector<vector<int>> mat(n, vector<int>(n));
8
9        int num = 1;
10
11        while (top <= bottom && left <= right) {
12
13            for (int i = left; i <= right; i++)
14                mat[top][i] = num++;
15            top++;
16
17            for (int j = top; j <= bottom; j++)
18                mat[j][right] = num++;
19            right--;
20
21            if (top <= bottom) {
22                for (int k = right; k >= left; k--)
23                    mat[bottom][k] = num++;
24                bottom--;
25            }
26
27            if (left <= right) {
28                for (int l = bottom; l >= top; l--)
29                    mat[l][left] = num++;
30                left++;
31            }
32        }
33        return mat;
34    }
35};
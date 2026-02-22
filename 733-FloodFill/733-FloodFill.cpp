// Last updated: 2/22/2026, 10:48:36 AM
1class Solution {
2public:
3    void dfs(vector<vector<int>>& image, int sr, int sc, int originalColor, int color) {
4        if (sr < 0 || sc < 0 || sr >= image.size() || sc >= image[0].size())
5            return;
6
7        if (image[sr][sc] != originalColor)
8            return;
9
10        image[sr][sc] = color;
11
12        dfs(image, sr + 1, sc, originalColor, color);
13        dfs(image, sr - 1, sc, originalColor, color);
14        dfs(image, sr, sc + 1, originalColor, color);
15        dfs(image, sr, sc - 1, originalColor, color);
16    }
17
18    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
19        int originalColor = image[sr][sc];
20
21        if (originalColor == color)
22            return image;
23            
24        dfs(image, sr, sc, originalColor, color);
25        return image;
26    }
27};
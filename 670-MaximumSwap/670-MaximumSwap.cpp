// Last updated: 7/14/2026, 10:24:47 AM
1class Solution {
2public:
3    int maximumSwap(int num) {
4        string numStr = to_string(num);
5        int n = numStr.size();
6
7        vector<int> maxRightIndex(n);
8        maxRightIndex[n - 1] = n - 1;
9
10        for (int i = n - 2; i >= 0; i--)
11            maxRightIndex[i] = (numStr[i] > numStr[maxRightIndex[i + 1]])
12                                   ? i
13                                   : maxRightIndex[i + 1];
14
15        for (int i = 0; i < n; i++) {
16            if (numStr[i] < numStr[maxRightIndex[i]]) {
17                swap(numStr[i], numStr[maxRightIndex[i]]);
18                int res = stoi(numStr);
19                return res;
20            }
21        }
22
23        return num;
24    }
25};
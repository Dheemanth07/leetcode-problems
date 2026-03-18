// Last updated: 3/18/2026, 8:16:52 PM
1class Solution {
2public:
3    int ladderLength(string beginWord, string endWord,
4                     vector<string>& wordList) {
5        unordered_set<string> ust(wordList.begin(), wordList.end());
6
7        if (ust.find(endWord) == ust.end())
8            return 0;
9
10        queue<string> q;
11        q.push(beginWord);
12
13        int steps = 1;
14
15        while (!q.empty()) {
16            int level = q.size();
17
18            for (int i = 0; i < level; i++) {
19                string top = q.front();
20                q.pop();
21
22                if (top == endWord)
23                    return steps;
24
25                for (int i = 0; i < top.size(); i++) {
26                    char original = top[i];
27
28                    for (char c = 'a'; c <= 'z'; c++) {
29                        top[i] = c;
30                        if (ust.find(top) != ust.end()) {
31                            q.push(top);
32                            ust.erase(top);
33                        }
34                    }
35                    top[i] = original;
36                }
37            }
38            steps++;
39        }
40        return 0;
41    }
42};
43
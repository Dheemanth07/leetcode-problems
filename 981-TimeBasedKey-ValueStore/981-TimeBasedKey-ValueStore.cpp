// Last updated: 6/25/2026, 10:05:18 AM
1class TimeMap {
2public:
3    unordered_map<string, vector<pair<int, string>>> mp;
4    TimeMap() {}
5
6    void set(string key, string value, int timestamp) {
7        mp[key].push_back({timestamp, value});
8    }
9
10    string get(string key, int timestamp) {
11        if (mp.find(key) == mp.end())
12            return "";
13
14        string res = "";
15        auto& p = mp[key];
16        int l = 0, r = p.size() - 1;
17
18        while (l <= r) {
19            int mid = l + (r - l) / 2;
20
21            if (p[mid].first <= timestamp) {
22                res = p[mid].second;
23                l = mid + 1;
24            } else
25                r = mid - 1;
26        }
27
28        return res;
29    }
30};
31
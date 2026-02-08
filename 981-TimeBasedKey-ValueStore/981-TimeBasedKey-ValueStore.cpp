// Last updated: 2/8/2026, 9:27:59 AM
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
13        string res = "";
14        auto& p = mp[key];
15        int l = 0, r = p.size() - 1;
16        while (l <= r) {
17            int mid = l + (r - l) / 2;
18            if (p[mid].first <= timestamp) {
19                res = p[mid].second;
20                l = mid + 1;
21            } else
22                r = mid - 1;
23        }
24        return res;
25    }
26};
27
// Last updated: 6/22/2026, 6:30:44 PM
class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> mp;
    TimeMap() {}

    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp) {
        if (mp.find(key) == mp.end())
            return "";
        string res = "";
        auto& p = mp[key];
        int l = 0, r = p.size() - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (p[mid].first <= timestamp) {
                res = p[mid].second;
                l = mid + 1;
            } else
                r = mid - 1;
        }
        return res;
    }
};

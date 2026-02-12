// Last updated: 2/12/2026, 5:47:58 PM
1class LRUCache {
2    int size;
3    list<int> lru_list;
4    unordered_map<int, pair<int, list<int>::iterator>> mp;
5
6public:
7    LRUCache(int capacity) { size = capacity; }
8
9    int get(int key) {
10        if (mp.find(key) == mp.end())
11            return -1;
12        lru_list.splice(lru_list.begin(), lru_list, mp[key].second);
13        return mp[key].first;
14    }
15
16    void put(int key, int value) {
17        if (mp.count(key)) {
18            // Update value and move to front
19            mp[key].first = value;
20            lru_list.splice(lru_list.begin(), lru_list, mp[key].second);
21            return;
22        }
23        if (lru_list.size() >= size) {
24            int last_key = lru_list.back();
25            lru_list.pop_back();
26            mp.erase(last_key);
27        }
28        lru_list.push_front(key);
29        mp[key] = {value, lru_list.begin()};
30    }
31};
32
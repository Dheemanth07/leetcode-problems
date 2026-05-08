// Last updated: 5/8/2026, 8:36:52 AM
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
12
13        lru_list.splice(lru_list.begin(), lru_list, mp[key].second);
14
15        return mp[key].first;
16    }
17
18    void put(int key, int value) {
19        if (mp.count(key)) {
20            // Update value and move to front
21            mp[key].first = value;
22
23            lru_list.splice(lru_list.begin(), lru_list, mp[key].second);
24
25            return;
26        }
27
28        if (lru_list.size() >= size) {
29            int last_key = lru_list.back();
30            lru_list.pop_back();
31            mp.erase(last_key);
32        }
33
34        lru_list.push_front(key);
35        mp[key] = {value, lru_list.begin()};
36    }
37};
38
// Last updated: 6/22/2026, 6:30:06 PM
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        for (int i = 0; i < mat.size(); i++) {
            int soldiers =
                upper_bound(mat[i].begin(), mat[i].end(), 1, greater<int>()) -
                mat[i].begin();
            pq.push({soldiers, i});
        }
        vector<int> res;
        while (k-- && !pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};
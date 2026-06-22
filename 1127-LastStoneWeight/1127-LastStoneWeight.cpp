// Last updated: 6/22/2026, 6:30:32 PM
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(),stones.end());
        while (pq.size()>1) {
            int largest = pq.top();
            pq.pop();
            int seclargest = pq.top();
            pq.pop();
            if(largest!=seclargest) pq.push(largest-seclargest);
        }
        return pq.empty()?0:pq.top();
    }
};
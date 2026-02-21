// Last updated: 2/21/2026, 8:47:17 PM
1class KthLargest {
2    int k;
3    priority_queue<int,vector<int>, greater<int>> minHeap;
4public:
5    KthLargest(int k, vector<int>& nums) {
6        this->k=k;
7        for(auto num:nums) add(num);
8    }
9    
10    int add(int val) {
11        minHeap.push(val);
12        if(minHeap.size()>k) minHeap.pop();
13        return minHeap.top();
14    }
15};
16
17/**
18 * Your KthLargest object will be instantiated and called as such:
19 * KthLargest* obj = new KthLargest(k, nums);
20 * int param_1 = obj->add(val);
21 */